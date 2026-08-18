// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import AutoImport from 'astro-auto-import';
import { readdirSync, statSync } from 'node:fs';
import { join, relative } from 'node:path';
import { remarkSiteLinks } from './src/plugins/remark-site-links';
import { vitePartials } from './src/plugins/vite-partials';
import { links } from './src/data/links';
import { SITE, BASE } from './src/data/site.mjs';

const EN_DOCS = 'src/content/docs/en';

/** Prefix a site-root path with the base, without doubling the slash when base is "/". */
const withBase = (path) => `${BASE.replace(/\/$/, '')}/${path.replace(/^\//, '')}`;

/**
 * Until this migration English lived at the site root, so every current page also
 * answers on its old root-level URL. Derived from the file tree, so a new English
 * page can never miss one.
 */
function rootLevelRedirects(dir = EN_DOCS) {
	const out = {};
	for (const entry of readdirSync(dir)) {
		const full = join(dir, entry);
		if (statSync(full).isDirectory()) {
			Object.assign(out, rootLevelRedirects(full));
			continue;
		}
		if (!/\.mdx?$/.test(entry)) continue;
		const slug = relative(EN_DOCS, full)
			.replace(/\.mdx?$/, '')
			.replace(/(^|\/)index$/, '');
		const tail = `${slug}${slug ? '/' : ''}`;
		// Astro applies `base` to the emitted file path but not to the target URL,
		// so the destination has to carry it explicitly.
		out[`/${tail}`] = withBase(`en/${tail}`);
	}
	return out;
}

/**
 * The Jekyll site's URLs, which are pasted all over Discord and the Subset forums.
 * The per-storefront pages are gone because FTL-Version-Rollback made the downgrade
 * identical everywhere, so they all land on the platform's install page.
 */
const jekyllRedirects = Object.fromEntries(
	Object.entries({
		'/install-guides/windows/': 'en/windows/manual-install/',
		'/install-guides/windows/steam-install/': 'en/windows/manual-install/',
		'/install-guides/windows/gog-install/': 'en/windows/manual-install/',
		'/install-guides/windows/humble-install/': 'en/windows/manual-install/',
		'/install-guides/windows/other-install/': 'en/windows/manual-install/',
		'/install-guides/linux/': 'en/linux/manual-install/',
		'/install-guides/linux/multiverse-install/': 'en/linux/manual-install/',
		'/install-guides/linux/genericlinux/select-game-copy/': 'en/linux/manual-install/',
		'/install-guides/linux/genericlinux/steam-install/': 'en/linux/manual-install/',
		'/install-guides/linux/genericlinux/gog-humble/': 'en/linux/manual-install/',
		'/install-guides/linux/steamdeck/select-game-copy/': 'en/steamos/manual-install/',
		'/install-guides/linux/steamdeck/steam-install/': 'en/steamos/manual-install/',
		'/install-guides/linux/steamdeck/gog-humble/': 'en/steamos/manual-install/',
		'/install-guides/mac/': 'en/macos/',
	}).map(([from, to]) => [from, withBase(to)]),
);

// https://astro.build/config
export default defineConfig({
	site: SITE,
	base: BASE,
	redirects: { ...rootLevelRedirects(), ...jekyllRedirects },
	markdown: { remarkPlugins: [remarkSiteLinks] },
	// Makes `@p/...` imports resolve to the importing file's own language.
	vite: { plugins: [vitePartials()] },
	integrations: [
		starlight({
			title: 'FTL Hyperspace',
			description: 'A binary mod for FTL: Faster Than Light',
			customCss: [
				'@fontsource/silkscreen/400.css',
				'./src/styles/theme.css',
				'./src/styles/global.css',
				'./src/styles/hero.css',
			],
			// Restores table-of-contents entries for headings that live in partials.
			routeMiddleware: './src/routeMiddleware.ts',
			components: {
				MobileTableOfContents: './src/components/MobileTableOfContents.astro',
				Hero: './src/components/Hero.astro',
			},
			social: [
				{
					icon: 'github',
					label: 'GitHub',
					href: 'https://github.com/FTL-Hyperspace/FTL-Hyperspace',
				},
				{ icon: 'discord', label: 'Discord', href: links.discord },
			],
			// Every language is an explicit directory under src/content/docs,
			// English included.
			defaultLocale: 'en',
			locales: {
				en: { label: 'English', lang: 'en' },
				de: { label: 'Deutsch', lang: 'de' },
				ko: { label: '한국어', lang: 'ko' },
				fr: { label: 'Français', lang: 'fr' },
			},
			sidebar: [
				{
					label: 'Windows',
					collapsed: true,
					items: [
						{ label: 'Overview', slug: 'windows' },
						{ label: 'Easy install', slug: 'windows/easy-install' },
						{ label: 'Manual install', slug: 'windows/manual-install' },
						{ label: 'Update', slug: 'windows/updating' },
						{ label: 'Fix a problem', slug: 'windows/troubleshooting' },
					],
				},
				{
					label: 'SteamOS',
					collapsed: true,
					items: [
						{ label: 'Overview', slug: 'steamos' },
						{ label: 'Easy install', slug: 'steamos/easy-install' },
						{ label: 'Manual install', slug: 'steamos/manual-install' },
						{ label: 'Update', slug: 'steamos/updating' },
						{ label: 'Fix a problem', slug: 'steamos/troubleshooting' },
					],
				},
				{
					label: 'Linux',
					collapsed: true,
					items: [
						{ label: 'Overview', slug: 'linux' },
						{ label: 'Easy install', slug: 'linux/easy-install' },
						{ label: 'Manual install', slug: 'linux/manual-install' },
						{ label: 'Update', slug: 'linux/updating' },
						{ label: 'Fix a problem', slug: 'linux/troubleshooting' },
					],
				},
				{
					label: 'macOS',
					collapsed: true,
					items: [
						{ label: 'Overview', slug: 'macos' },
						{ label: 'Easy install', slug: 'macos/easy-install' },
						{ label: 'Manual install', slug: 'macos/manual-install' },
						{ label: 'Update', slug: 'macos/updating' },
						{ label: 'Migrate saves', slug: 'macos/migrate-saves' },
						{ label: 'Fix a problem', slug: 'macos/troubleshooting' },
					],
				},
								{
					label: 'Reference',
					items: [
						{ label: 'Feature defaults', slug: 'features' },
						{ label: 'Console commands', slug: 'console' },
						{ label: 'Vanilla ids', slug: 'vanilla-ids' },
					],
				},
			],
		}),
		// Starlight's building blocks are used on nearly every page,
		// so we rather auto import them

		// Has to sit AFTER starlight(). AutoImport does nothing unless @astrojs/mdx
		// is already in the integrations list.

		// The "@astrojs/mdx initialized BEFORE astro-auto-import" warning on build is
		// expected. Starlight adds mdx itself, so the order check misfires. The auto
		// imports still work. https://github.com/delucis/astro-auto-import/issues/46
		AutoImport({
			imports: [
				{ '@astrojs/starlight/components': ['Aside', 'Card', 'FileTree', 'Steps', 'TabItem', 'Tabs'] },
			],
		}),
	],
});
