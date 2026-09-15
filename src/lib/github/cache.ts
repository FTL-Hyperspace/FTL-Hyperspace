/** Caches GitHub release downloads in localStorage for REFRESH_TIME. */
import { fetchReleaseDownloads, type ReleaseDownloads } from './releases';

/** How long a cached copy of the release data is used before asking GitHub again. */
const REFRESH_TIME = 60 * 60 * 1000;
/** Oldest cached copy still shown when GitHub cannot be reached. Past this, show nothing rather than an outdated version. */
const MAX_STALE_TIME = 24 * 60 * 60 * 1000;

const CACHE_KEY = 'gh-metrics:releases';

export interface Snapshot {
	fetchedAt: number;
	releases: ReleaseDownloads[];
}

/** Storage can be missing or throw in private windows, so a failure just means no cache. */
function readCache(): Snapshot | null {
	try {
		const cached = localStorage.getItem(CACHE_KEY);
		return cached ? (JSON.parse(cached) as Snapshot) : null;
	} catch {
		return null;
	}
}

function writeCache(snapshot: Snapshot): void {
	try {
		localStorage.setItem(CACHE_KEY, JSON.stringify(snapshot));
	} catch {
		// Full or blocked storage only costs the next visit a refetch.
	}
}

/**
 * A fresh cache is used as is. Otherwise GitHub is asked again,
 * and if that fails a stale cache is shown, up to MAX_STALE_TIME old.
 */
export async function loadSnapshot(): Promise<Snapshot> {
	const cached = readCache();
	const cacheAge = cached ? Date.now() - cached.fetchedAt : Infinity;
	if (cached && cacheAge < REFRESH_TIME) return cached;

	try {
		const snapshot = { fetchedAt: Date.now(), releases: await fetchReleaseDownloads() };
		writeCache(snapshot);
		return snapshot;
	} catch (error) {
		if (cached && cacheAge < MAX_STALE_TIME) return cached;
		throw error;
	}
}
