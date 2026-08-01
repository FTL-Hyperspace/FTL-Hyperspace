#!/usr/bin/env node
/**
 * Lists every translation that needs work, in one place.
 *
 * A page is stale when it either does not exist, or was last touched before the
 * English page it translates. Missing is a file-tree comparison and always
 * works; outdated needs git history, so it is skipped for files not committed
 * yet rather than reported wrongly.
 *
 * Run with --strict to exit non-zero when something is outdated. Missing pages
 * never fail: they are a known backlog, not something a change introduced.
 */
import { readdirSync, statSync, existsSync } from 'node:fs';
import { execFileSync } from 'node:child_process';
import { join, relative } from 'node:path';

const DOCS = 'src/content/docs';
const SOURCE = 'en';
const LOCALES = ['de', 'fr', 'ko'];
const strict = process.argv.includes('--strict');

const walk = (dir) =>
	existsSync(dir)
		? readdirSync(dir).flatMap((e) => {
				const full = join(dir, e);
				return statSync(full).isDirectory() ? walk(full) : [full];
			})
		: [];

/** Unix time of the last commit touching a path, or null if never committed. */
const lastCommit = (path) => {
	try {
		const out = execFileSync('git', ['log', '-1', '--format=%ct', '--', path], {
			encoding: 'utf8',
			stdio: ['ignore', 'pipe', 'ignore'],
		}).trim();
		return out ? Number(out) : null;
	} catch {
		return null;
	}
};

const pages = walk(join(DOCS, SOURCE)).filter((f) => /\.mdx?$/.test(f));
const partials = walk(join(DOCS, '_partials', SOURCE)).filter((f) => /\.mdx?$/.test(f));

const rows = [];
let uncommitted = 0;

const compare = (sourceFile, targetFile, label) => {
	if (!existsSync(targetFile)) {
		rows.push({ label, file: relative(DOCS, targetFile), why: 'missing' });
		return;
	}
	const a = lastCommit(sourceFile);
	const b = lastCommit(targetFile);
	if (a === null || b === null) {
		uncommitted++;
		return;
	}
	if (a > b) {
		const days = Math.round((a - b) / 86400);
		rows.push({ label, file: relative(DOCS, targetFile), why: `outdated by ${days}d` });
	}
};

for (const locale of LOCALES) {
	for (const src of pages) {
		compare(src, join(DOCS, locale, relative(join(DOCS, SOURCE), src)), locale);
	}
	for (const src of partials) {
		compare(src, join(DOCS, '_partials', locale, relative(join(DOCS, '_partials', SOURCE), src)), locale);
	}
}

const total = (pages.length + partials.length) * LOCALES.length;
console.log(`${pages.length} pages and ${partials.length} partials in "${SOURCE}", ${LOCALES.length} other languages`);
console.log(`${total - rows.length} of ${total} translations up to date\n`);

if (!rows.length) {
	console.log('nothing stale');
} else {
	for (const locale of LOCALES) {
		const mine = rows.filter((r) => r.label === locale);
		if (!mine.length) continue;
		console.log(`${locale}  (${mine.length})`);
		for (const r of mine) console.log(`    ${r.why.padEnd(14)} ${r.file}`);
		console.log();
	}
}

if (uncommitted) {
	console.log(`note: ${uncommitted} pairs skipped for the outdated check, not committed yet.`);
}

if (strict && rows.some((r) => r.why !== 'missing')) process.exit(1);
