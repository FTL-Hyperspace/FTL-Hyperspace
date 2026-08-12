#!/usr/bin/env node
/**
 * Validates every internal link and in-page anchor in the built site.
 *
 * Catches dead paths and anchors that drifted from their heading — the latter
 * happens when a translation renames a heading but leaves the English #anchor
 * in the link. Run after `npm run build`.
 */
import { readFileSync, existsSync, statSync, readdirSync } from 'node:fs';
import { join, posix } from 'node:path';
import { BASE } from '../src/data/site.mjs';

const DIST = 'dist';

const walk = (dir) =>
	readdirSync(dir).flatMap((e) => {
		const full = join(dir, e);
		return statSync(full).isDirectory() ? walk(full) : [full];
	});

if (!existsSync(DIST)) {
	console.error('dist/ not found — run `npm run build` first.');
	process.exit(1);
}

const pages = walk(DIST).filter((f) => f.endsWith('.html'));
const isFile = (p) => existsSync(p) && statSync(p).isFile();

// Trailing slash stripped so "/" and "/FTL-Hyperspace" are handled the same way.
const PREFIX = BASE.replace(/\/$/, '');

const fileFor = (urlPath) => {
	if (!urlPath.startsWith(PREFIX)) return null;
	const rel = urlPath.slice(PREFIX.length) || '/';
	for (const c of [DIST + rel, posix.join(DIST + rel, 'index.html'), DIST + rel + '.html']) {
		if (isFile(c)) return c;
	}
	return null;
};

const idCache = new Map();
const idsOf = (file) => {
	if (!idCache.has(file)) {
		const html = readFileSync(file, 'utf8');
		idCache.set(file, new Set([...html.matchAll(/\sid="([^"]+)"/g)].map((m) => m[1])));
	}
	return idCache.get(file);
};

const broken = [];
let links = 0;
let anchors = 0;

for (const page of pages) {
	const html = readFileSync(page, 'utf8');
	const pageUrl = BASE + page.slice(DIST.length).replace(/index\.html$/, '');

	for (const [, href] of html.matchAll(/(?:href|src)="([^"]+)"/g)) {
		if (/^(https?:|mailto:|data:|\/\/|#$)/.test(href)) continue;
		const [pathPart, frag] = href.split('#');
		const abs = !pathPart
			? pageUrl
			: pathPart.startsWith('/')
				? pathPart
				: posix.resolve(pageUrl, pathPart);

		if (pathPart) {
			links++;
			if (!fileFor(abs)) {
				broken.push(`${pageUrl}  ->  ${href}  (dead path)`);
				continue;
			}
		}
		if (frag) {
			const target = fileFor(abs);
			if (!target) continue;
			anchors++;
			if (!idsOf(target).has(decodeURIComponent(frag))) {
				broken.push(`${pageUrl}  ->  ${href}  (no such anchor)`);
			}
		}
	}
}

console.log(`checked ${links} links and ${anchors} anchors across ${pages.length} pages`);
const uniq = [...new Set(broken)];
if (uniq.length) {
	console.log(`\nBROKEN (${uniq.length}):`);
	console.log(uniq.map((b) => '  ' + b).join('\n'));
	process.exit(1);
}
console.log('all resolve');
