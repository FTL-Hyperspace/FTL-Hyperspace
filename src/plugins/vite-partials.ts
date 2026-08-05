import { existsSync } from 'node:fs';
import { resolve } from 'node:path';

const PARTIALS = resolve('src/content/docs/_partials');
const SOURCE_LANG = 'en';

/**
 * The language folder a file sits in. Partials are checked first, because their
 * path contains both markers.
 */
function languageOf(importer = ''): string {
	const tail = importer.split('/_partials/')[1] ?? importer.split('/docs/')[1];
	return tail?.split('/')[0] ?? SOURCE_LANG;
}

/**
 * Resolves `@p/<group>/<name>.mdx` against the importing file's own language.
 *
 * One import line reads the same everywhere: a French page writing
 * `@p/shared/_intro-setup.mdx` gets `_partials/fr/shared/_intro-setup.mdx`, and
 * falls back to the English copy while that translation does not exist. That
 * matches what Starlight already does for pages, so a half-translated language
 * renders instead of failing the build.
 *
 * tsconfig points `@p/*` at the English copies too. That is only what gives the
 * editor go-to-definition; the per-language part happens here.
 */
export function vitePartials() {
	return {
		name: 'partials-by-language',
		enforce: 'pre' as const,
		resolveId(source: string, importer: string | undefined) {
			if (!source.startsWith('@p/')) return null;
			const path = source.slice(3);
			const localised = resolve(PARTIALS, languageOf(importer), path);
			return existsSync(localised) ? localised : resolve(PARTIALS, SOURCE_LANG, path);
		},
	};
}
