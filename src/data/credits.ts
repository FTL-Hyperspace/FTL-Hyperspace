/**
 * Single source of truth for the credits shown on every locale's homepage.
 * Names are not translated, so adding a contributor here updates all languages.
 * The section headings live in src/content/i18n/<lang>.json.
 *
 * A bare string is someone we have no GitHub username for.
 * An object with `name` and `github` is someone we can link to.
 */
export type Person = string | { name: string; github: string };

export const credits = {
	development: [
		{ name: 'TheSwiftTiger', github: 'TheSwiftTiger' },
		{ name: 'Amyseni (Winderps)', github: 'Amyseni' },
		{ name: 'ih8ih8sn0w', github: 'ih8ih8sn0w' },
		{ name: 'Admiral Billy', github: 'Admiral-Billy' },
		{ name: 'laszlogasd', github: 'laszlogasd' },
		{ name: 'mathchamp93', github: 'mathchamp93' },
		{ name: 'Mr. Doom', github: 'Nasa62' },
		{ name: 'Chrono Vortex', github: 'ChronoVortex' },
		{ name: 'Pepson', github: 'THETASOLA' },
		{ name: 'ranhai', github: 'ranhai613' },
		{ name: 'sillysandvich', github: 'sillysandvich' },
		{ name: 'The Dumb Dino', github: 'The-Dumb-Dino' },
		{ name: 'ZeroFreed', github: 'fr-eed' },
	],
	art: ['SaltyFriedRice'],
	specialThanks: [
		{ name: '_Kilburn', github: 'UnderscoreKilburn' },
		{ name: 'slow (slowriderxcorps)', github: 'slowriderxcorps' },
		{ name: 'Qaser7', github: 'Qaser7' },
		'Masala',
		'bamalf',
		{ name: 'Zevee (Kix)', github: 'Kix-ZM' },
		{ name: 'BlizzArchonJ', github: 'blizzarchon' },
		'Paradigm',
		'FTL Multiverse Team',
	],
} as const satisfies Record<string, readonly Person[]>;
