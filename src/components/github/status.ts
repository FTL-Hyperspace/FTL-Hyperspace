/**
 * Loads GitHub metrics once per page and records the outcome as
 * <html data-gh="loaded|failed">, which global.css uses to show or remove
 * .gh-pending and .gh-collapsed elements. Resolves to null on failure.
 */
import { GhMetrics, type ReleasePeriod } from '~/lib/github/metrics';

export interface LoadedMetrics {
	metrics: GhMetrics;
	latest: ReleasePeriod;
}

async function loadMetrics(): Promise<LoadedMetrics | null> {
	try {
		const metrics = await GhMetrics.instance.load();
		const latest = metrics.latestRelease;
		document.documentElement.dataset.gh = latest ? 'loaded' : 'failed';
		return latest ? { metrics, latest } : null;
	} catch (error) {
		document.documentElement.dataset.gh = 'failed';
		console.error('GitHub metrics:', error);
		return null;
	}
}

export const loadedMetrics = loadMetrics();
