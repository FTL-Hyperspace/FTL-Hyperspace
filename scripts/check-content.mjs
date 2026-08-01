#!/usr/bin/env node
// Every URL in src/content must come from src/data/links.ts as `link:<key>`.
import { execSync } from 'node:child_process';

const hits = execSync("grep -rnE 'https?://' src/content || true", { encoding: 'utf8' }).trim();
if (hits) console.log(`${hits}\n\nRaw URLs belong in src/data/links.ts — use link:<key>.`);
process.exit(hits ? 1 : 0);
