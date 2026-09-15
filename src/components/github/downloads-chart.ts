/** Draws the running-total downloads chart as SVG with hover readings. */
import { minIndex } from 'd3-array';
import { scaleLinear, scaleTime } from 'd3-scale';
import { area, curveMonotoneX, line } from 'd3-shape';
import { timeYear } from 'd3-time';
import type { ReleasePeriod } from '~/lib/github/metrics';

interface ChartPoint {
	/** Release tag, or null for the closing point at the last fetch. */
	tag: string | null;
	date: Date;
	total: number;
}

/** What the hover guide, marker and tooltip show for one pointer position. */
interface Reading {
	px: number;
	py: number;
	value: string;
	caption: string;
}

const SVG_NS = 'http://www.w3.org/2000/svg';
const HEIGHT = 240;
const PAD = { top: 12, right: 12, bottom: 24, left: 44 };
/** Space between an axis label and the plot area. */
const LABEL_GAP = 8;
/** How close, in pixels, the pointer has to be to a release to show its exact numbers. */
const SNAP_DISTANCE = 8;
/** Halvings of the path length when looking up the curve's height; 24 is far below a pixel. */
const PATH_SEARCH_STEPS = 24;

const clamp = (value: number, min: number, max: number) => Math.min(Math.max(value, min), max);

function svg<K extends keyof SVGElementTagNameMap>(tag: K, attrs: Record<string, string | number>, parent: Element) {
	const element = document.createElementNS(SVG_NS, tag);
	for (const [name, value] of Object.entries(attrs)) element.setAttribute(name, String(value));
	parent.append(element);
	return element;
}

/**
 * A point at each release's publish date holding the downloads of earlier
 * releases, and a closing point at the last fetch holding the full total.
 * Expects at least one release.
 */
function toChartPoints(releases: ReleasePeriod[]): ChartPoint[] {
	const newest = releases.at(-1)!;
	return [
		...releases.map((release) => ({ tag: release.tag, date: release.startDate, total: release.downloadsAtStart })),
		{ tag: null, date: newest.endDate, total: newest.downloadsAtEnd },
	];
}

/**
 * Height of the drawn line at `px`. d3 builds the path but cannot evaluate it,
 * so search along the path instead: x only grows along it, so halving the
 * length range homes in on the spot directly above `px`.
 */
function heightAt(path: SVGPathElement, px: number): number {
	let before = 0;
	let after = path.getTotalLength();
	for (let step = 0; step < PATH_SEARCH_STEPS; step++) {
		const middle = (before + after) / 2;
		if (path.getPointAtLength(middle).x < px) before = middle;
		else after = middle;
	}
	return path.getPointAtLength(after).y;
}

function draw(plot: HTMLElement, points: ChartPoint[], label: string): void {
	const lang = document.documentElement.lang;
	const width = plot.clientWidth;
	const compact = new Intl.NumberFormat(lang, { notation: 'compact' });
	const full = new Intl.NumberFormat(lang);
	const day = new Intl.DateTimeFormat(lang, { dateStyle: 'medium' });

	const x = scaleTime()
		.domain([points[0].date, points.at(-1)!.date])
		.range([PAD.left, width - PAD.right]);
	const y = scaleLinear()
		.domain([0, points.at(-1)!.total])
		.nice(4)
		.range([HEIGHT - PAD.bottom, PAD.top]);

	const root = document.createElementNS(SVG_NS, 'svg');
	root.setAttribute('viewBox', `0 0 ${width} ${HEIGHT}`);
	root.setAttribute('height', String(HEIGHT));
	root.setAttribute('role', 'img');
	root.setAttribute('aria-label', label);

	for (const value of y.ticks(4)) {
		svg('line', { class: 'grid', x1: PAD.left, x2: width - PAD.right, y1: y(value), y2: y(value) }, root);
		const tick = svg('text', { class: 'tick', x: PAD.left - LABEL_GAP, y: y(value), 'text-anchor': 'end', 'dominant-baseline': 'middle' }, root);
		tick.textContent = compact.format(value);
	}

	for (const year of x.ticks(timeYear)) {
		const tick = svg('text', { class: 'tick', x: x(year), y: HEIGHT - PAD.bottom + LABEL_GAP, 'text-anchor': 'middle', 'dominant-baseline': 'hanging' }, root);
		tick.textContent = String(year.getFullYear());
	}

	const coords = points.map((point): [number, number] => [x(point.date), y(point.total)]);
	svg('path', { class: 'area', d: area().curve(curveMonotoneX).y0(y(0))(coords)! }, root);
	const linePath = svg('path', { class: 'line', d: line().curve(curveMonotoneX)(coords)! }, root);

	function readingAtPoint(index: number): Reading {
		const point = points[index];
		return {
			px: coords[index][0],
			py: coords[index][1],
			value: full.format(point.total),
			caption: point.tag ? `${day.format(point.date)} · ${point.tag}` : day.format(point.date),
		};
	}

	/** Exact numbers near a release; between releases, an estimate read off the curve. */
	function readingAt(pointerX: number): Reading {
		const px = clamp(pointerX, x.range()[0], x.range()[1]);
		const nearest = minIndex(coords, ([cx]) => Math.abs(cx - px));
		if (Math.abs(coords[nearest][0] - px) <= SNAP_DISTANCE) return readingAtPoint(nearest);

		const py = heightAt(linePath, px);
		return {
			px,
			py,
			value: `≈ ${full.format(Math.round(y.invert(py)))}`,
			caption: day.format(x.invert(px)),
		};
	}

	const hover = svg('g', { visibility: 'hidden' }, root);
	const guide = svg('line', { class: 'guide', y1: PAD.top, y2: HEIGHT - PAD.bottom }, hover);
	const marker = svg('circle', { class: 'marker', r: 4.5 }, hover);

	const tooltip = document.createElement('div');
	tooltip.className = 'tooltip';
	tooltip.hidden = true;
	const tooltipValue = tooltip.appendChild(document.createElement('strong'));
	const tooltipCaption = tooltip.appendChild(document.createElement('span'));

	function show({ px, py, value, caption }: Reading): void {
		guide.setAttribute('x1', String(px));
		guide.setAttribute('x2', String(px));
		marker.setAttribute('cx', String(px));
		marker.setAttribute('cy', String(py));
		hover.setAttribute('visibility', 'visible');

		tooltipValue.textContent = value;
		tooltipCaption.textContent = caption;
		tooltip.hidden = false;
		// Centred over the pointer, but pushed back inside the chart near either edge.
		const halfWidth = tooltip.offsetWidth / 2;
		tooltip.style.left = `${clamp(px, halfWidth, width - halfWidth)}px`;
		tooltip.style.top = `${py}px`;
	}

	function hide(): void {
		hover.setAttribute('visibility', 'hidden');
		tooltip.hidden = true;
	}

	root.addEventListener('pointermove', (event) => {
		show(readingAt(event.clientX - root.getBoundingClientRect().left));
	});
	root.addEventListener('pointerleave', hide);

	// Keyboard: left and right step through releases, up and down jump to the end and start.
	root.setAttribute('tabindex', '0');
	// Screen readers read out whatever is written here, since the tooltip changes silently.
	const announcer = document.createElement('div');
	announcer.className = 'sr-only';
	announcer.setAttribute('aria-live', 'polite');
	let active = points.length - 1;
	root.addEventListener('keydown', (event) => {
		const last = points.length - 1;
		const next = { ArrowLeft: active - 1, ArrowRight: active + 1, ArrowUp: last, ArrowDown: 0 }[event.key];
		if (next === undefined) return;
		event.preventDefault();
		active = clamp(next, 0, last);
		const reading = readingAtPoint(active);
		show(reading);
		announcer.textContent = `${reading.value}, ${reading.caption}`;
	});
	root.addEventListener('blur', hide);

	plot.replaceChildren(root, tooltip, announcer);
}

/** Draw the chart into `plot` and redraw whenever its width changes. Expects at least one release. */
export function drawDownloadsChart(plot: HTMLElement, releases: ReleasePeriod[], label: string): void {
	const points = toChartPoints(releases);
	let drawnWidth = 0;
	new ResizeObserver(() => {
		if (plot.clientWidth === drawnWidth) return;
		drawnWidth = plot.clientWidth;
		draw(plot, points, label);
	}).observe(plot);
}
