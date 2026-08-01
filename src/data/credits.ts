/**
 * Single source of truth for the credits shown on every locale's homepage.
 * Names are not translated, so adding a contributor here updates all languages.
 * The section headings live in src/content/i18n/<lang>.json.
 */
export const credits = {
	development: [
		'TheSwiftTiger',
		'Amyseni (Winderps)',
		'ih8ih8sn0w',
		'Admiral Billy',
		'laszlogasd',
		'mathchamp93',
		'Mr. Doom',
		'Chrono Vortex',
		'Pepson',
		'ranhai',
		'sillysandvich',
		'The Dumb Dino',
	],
	art: ['SaltyFriedRice'],
	specialThanks: [
		'_Kilburn',
		'zerofreed',
		'slow (slowriderxcorps)',
		'Masala',
		'bamalf',
		'Puffias Leroy McBillington III (KingdomKrafters/Kix)',
		'BlizzArchonJ (mr_easy_money)',
		'Paradigm',
		'FTL Multiverse Team',
	],
} as const;
