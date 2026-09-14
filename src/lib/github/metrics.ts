/** Shared, cached GitHub release metrics for Hyperspace. Unauthenticated: 60 calls an hour per IP. */
import { loadSnapshot, type Snapshot } from './cache';

/** One release's stretch of the timeline, from its publish date until the next one. */
export interface ReleasePeriod {
	tag: string;
	/** When this release was published. */
	startDate: Date;
	/** When the next release was published, or the last fetch for the newest one. */
	endDate: Date;
	/** Downloads of every earlier release, the running total at startDate. */
	downloadsAtStart: number;
	/** downloadsAtStart plus this release, the running total at endDate. */
	downloadsAtEnd: number;
}

/**
 * Releases oldest first. Each one's downloads are only counted from the next
 * release on, so the running totals never credit a version before it existed.
 */
function toReleasePeriods({ fetchedAt, releases }: Snapshot): ReleasePeriod[] {
	const ordered = [...releases].sort((a, b) => a.publishedAt - b.publishedAt);

	let total = 0;
	return ordered.map(({ tag, publishedAt, downloads }, i) => {
		const downloadsAtStart = total;
		total += downloads;
		return {
			tag,
			startDate: new Date(publishedAt),
			endDate: new Date(ordered[i + 1]?.publishedAt ?? fetchedAt),
			downloadsAtStart,
			downloadsAtEnd: total,
		};
	});
}

/**
 * Call load() once, then read the getters. Every caller shares one request; the
 * cache decides whether it reaches GitHub. Before the first load the getters are empty.
 */
export class GhMetrics {
	static readonly instance = new GhMetrics();

	#request: Promise<GhMetrics> | null = null;
	#releases: ReleasePeriod[] = [];

	private constructor() {}

	load(): Promise<GhMetrics> {
		this.#request ??= loadSnapshot().then(
			(snapshot) => {
				this.#releases = toReleasePeriods(snapshot);
				return this;
			},
			(error) => {
				// Forget the failure so the next caller tries again.
				this.#request = null;
				throw error;
			},
		);
		return this.#request;
	}

	/** Releases oldest first, with running download totals. */
	get releases(): ReleasePeriod[] {
		return this.#releases;
	}

	/** The newest release, or undefined when none are loaded. */
	get latestRelease(): ReleasePeriod | undefined {
		return this.#releases.at(-1);
	}

	/** Downloads of every release combined. */
	get totalDownloads(): number {
		return this.latestRelease?.downloadsAtEnd ?? 0;
	}
}
