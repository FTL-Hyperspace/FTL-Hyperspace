# FTL: Hyperspace website

Install guides for players, built with [Astro Starlight](https://starlight.astro.build).
Deployed to GitHub Pages on every push to `gh-pages-source`.

## Running it

Needs Node 22.

```sh
npm install
npm run dev      # http://localhost:4321/FTL-Hyperspace/
```

The dev server serves under `/FTL-Hyperspace/` because that is the project-site
path on GitHub Pages. Set `SITE_BASE=/` to build for a host that serves from the root.

```sh
npm run check    # reject raw URLs, build, then validate every link and anchor
```

Run that before pushing. It is what CI runs.

## Layout

```
src/
  content/docs/
    en/                 English guides are the source
    de/  fr/  ko/       translations, same file names as en/
    _partials/en/       reusable chunks shared between guides
  data/links.ts         every external URL, one key each
  components/           Custom components reused in docs
  assets/               images and video
scripts/                the three check:* scripts
astro.config.mjs        base path, locales, sidebar, redirects
```

### Partials

Plenty of steps repeat across platforms: finding the FTL folder, patching with a
mod manager, the generic troubleshooting list. Each is written once in
`src/content/docs/_partials/en/` and imported wherever it is needed:

```mdx
import Troubleshooting from '~/content/docs/_partials/en/_troubleshooting.mdx';

<Troubleshooting />
```

The `_` prefix keeps a file out of the router, so a partial never becomes a page
of its own. A few accept props to adjust a step per platform, like
`<Multiverse ftlmanOnly />`. Read a partial before editing it: the change shows up
on every page that imports it.

### Links

No page contains a raw URL. External links are written `link:<key>` and resolved
from `src/data/links.ts` by a remark plugin:

```md
Ask on the [Discord](link:discord).
```

An unknown key fails the build. `npm run check:content` fails if a raw `http://`
or `https://` appears anywhere under `src/content`. One URL changing is then one
edit, not a search across four languages.

## Translating

A translated page is the same path with the language swapped: `en/windows/updating.mdx`
becomes `de/windows/updating.mdx`. Partials mirror the same way, into
`_partials/de/`, and the importing page points at its own language's copy.

To see what needs work run:

```sh
npm run check:stale
```

It lists, per language, every page and partial that is either **missing** or **outdated**.

Outdated meaning the English file has been committed to more recently than its translation.
