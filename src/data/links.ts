/**
 * Every external URL used by the guides, in one place.
 *
 * Reference these from Markdown as `link:<key>`, e.g.
 *   [Download Hyperspace](link:releases)
 * The remark-site-links plugin resolves them at build time and fails the build
 * on an unknown key, so a rename can never silently leave a dead link behind.
 */
export const links = {
	discord: 'https://discord.gg/hhs5ecx',
	discordFrench: 'https://discord.gg/3jEqT38Sh4',
	discordMacSupport: 'https://discord.com/channels/604415384979898464/1199977570750431313',

	releases: 'https://github.com/FTL-Hyperspace/FTL-Hyperspace/releases/latest',
	wiki: 'https://github.com/FTL-Hyperspace/FTL-Hyperspace/wiki',

	// Rolls any Windows storefront build back to 1.6.9
	rollback: 'https://github.com/FTL-Hyperspace/FTL-Version-Rollback',
	rollbackZip: 'https://github.com/FTL-Hyperspace/FTL-Version-Rollback/archive/refs/heads/main.zip',

	// Mod manager with a built-in automatic Hyperspace installer. Supersedes
	// Slipstream for most setups and is what the macOS installer drives.
	ftlman: 'https://github.com/afishhh/ftlman',
	ftlmanReleases: 'https://github.com/afishhh/ftlman/releases/latest',

	multiverseForum: 'https://subsetgames.com/forum/viewtopic.php?f=11&t=35332',
	// Alternative download source: the Multiverse forum's own downloads board
	multiverseDownloads: 'https://ftlmultiverse.boards.net/board/7/official-downloads',
	insurrectionForum: 'https://subsetgames.com/forum/viewtopic.php?t=37167',
	slipstreamForum: 'https://subsetgames.com/forum/viewtopic.php?f=12&t=17102',

} as const;

export type LinkKey = keyof typeof links;
