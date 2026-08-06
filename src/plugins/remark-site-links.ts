import { links } from '../data/links';

const SCHEME = /^link:([A-Za-z][A-Za-z0-9]*)$/;
const INLINE = /link:([A-Za-z][A-Za-z0-9]*)/g;

/**
 * Resolves `link:<key>` URLs against src/data/links.ts.
 *
 * Runs for Markdown and MDX alike, so guide pages can stay plain `.md` instead
 * of being promoted to MDX just to reference a shared URL.
 */
export function remarkSiteLinks() {
	return (tree: any, file: any) => {
		const resolve = (key: string): string => {
			const url = (links as Record<string, string>)[key];
			if (!url) {
				throw new Error(
					`remark-site-links: unknown key "${key}" in ${file.path ?? 'unknown file'}. ` +
						`Add it to src/data/links.ts or fix the typo.`,
				);
			}
			return url;
		};

		const walk = (node: any) => {
			const match = typeof node.url === 'string' && node.url.match(SCHEME);
			if (match) node.url = resolve(match[1]);

			// Raw HTML blocks (<iframe>) aren't link nodes, so their src never
			// reaches the branch above. Substitute in the raw string instead.
			if (node.type === 'html' && typeof node.value === 'string' && node.value.includes('link:')) {
				node.value = node.value.replace(INLINE, (_: string, key: string) => resolve(key));
			}

			for (const child of node.children ?? []) walk(child);
		};

		walk(tree);
	};
}
