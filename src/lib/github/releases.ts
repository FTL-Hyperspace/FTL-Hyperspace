/** Reads Hyperspace's published releases and their download counts from GitHub. */

const RELEASES_API = 'https://api.github.com/repos/FTL-Hyperspace/FTL-Hyperspace/releases';
/** GitHub's maximum page size. */
const PAGE_SIZE = 100;

interface Release {
	tag_name: string;
	published_at: string | null;
	draft: boolean;
	prerelease: boolean;
	assets: { download_count: number }[];
}

/** The part of a release the metrics need, small enough to cache. */
export interface ReleaseDownloads {
	tag: string;
	publishedAt: number;
	downloads: number;
}

async function fetchReleasePages(): Promise<Release[]> {
	const releases: Release[] = [];
	for (let page = 1; ; page++) {
		const response = await fetch(`${RELEASES_API}?per_page=${PAGE_SIZE}&page=${page}`);
		if (!response.ok) throw new Error(`GitHub releases API answered ${response.status}`);
		const batch: Release[] = await response.json();
		releases.push(...batch);
		if (batch.length < PAGE_SIZE) return releases;
	}
}

/**
 * Fetch every published release. Returns tag, publish time and summed asset downloads.
 * Skips prereleases, as GitHub's /releases/latest page does.
 */
export async function fetchReleaseDownloads(): Promise<ReleaseDownloads[]> {
	const releases = await fetchReleasePages();
	return releases
		.filter((release): release is Release & { published_at: string } => !release.draft && !release.prerelease && release.published_at !== null)
		.map((release) => ({
			tag: release.tag_name,
			publishedAt: Date.parse(release.published_at),
			downloads: release.assets.reduce((sum, asset) => sum + asset.download_count, 0),
		}));
}
