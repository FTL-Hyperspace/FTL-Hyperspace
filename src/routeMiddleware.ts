import type { MarkdownHeading } from 'astro';
import { defineRouteMiddleware } from '@astrojs/starlight/route-data';
import { getHeadings as troubleshootingHeadings } from '~/content/docs/_partials/en/_troubleshooting.mdx';

/** Shape Starlight nests its ToC into. Not exported by the package. */
type TocItem = MarkdownHeading & { children: TocItem[] };

/**
 * Puts headings from imported partials back into the table of contents.
 *
 * Astro builds a page's heading list from that page's own source AST, where a
 * partial is still an unrendered `<Component />`. Headings written inside one
 * end up in the HTML but never in the list, and Starlight builds the ToC from
 * the list, so a page whose sections all live in a partial gets an empty ToC.
 *
 * The page/partial relationship only exists at compile time, so the pages have
 * to be named here. A partial that grows a heading without being registered
 * below will render it fine but leave it out of the ToC.
 */
const REGISTRY: Array<{ pages: RegExp; headings: MarkdownHeading[] }> = [
	{ pages: /\/troubleshooting$/, headings: troubleshootingHeadings() },
];

/**
 * Mirrors Starlight's own nesting rule: an entry goes as deep in the tree as its
 * depth requires. Reimplemented because `utils/generateToC` is not exported.
 */
function inject(items: TocItem[], item: TocItem): void {
	const last = items.at(-1);
	if (!last || last.depth >= item.depth) items.push(item);
	else inject(last.children, item);
}

export const onRequest = defineRouteMiddleware(({ locals }) => {
	const { toc, id } = locals.starlightRoute;
	if (!toc) return;

	for (const { pages, headings } of REGISTRY) {
		if (!pages.test(id)) continue;
		for (const heading of headings) {
			if (heading.depth < toc.minHeadingLevel || heading.depth > toc.maxHeadingLevel) continue;
			// Appended, which is only right because every registered page renders
			// its partial last. Move a partial mid-page and its entries will still
			// land at the bottom of the ToC.
			inject(toc.items, { ...heading, children: [] });
		}
	}
});
