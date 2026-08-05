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
    _partials/en/       reusable chunks, grouped by what varies
      shared/           can be reused by multiple platforms
      platform/         platform specific (excep steamdeck/linux)
      manager/          ftlman / slipstream specific
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
import Troubleshooting from "@p/shared/_troubleshooting.mdx";

<Troubleshooting />
```

`@p/` carries no language. `src/plugins/vite-partials.ts` resolves it against the
importing file's own language and falls back to English (default) if language specific
file doesn't exist

Starlight's own components (`Aside`, `Steps`, `Tabs`, `Card`, `FileTree`, `TabItem`)
need no import at all, see `astro.config.mjs`.

Names read `<scope>-<object>-<action>`, general to specific, so everything for one
platform or one mod manager sorts together: `ftlman-hyperspace-update`,
`windows-ftl-rollback`, `linux-saves`.

Every partial keeps its leading `_`. Starlight's loader treats anything without it
as a page.

Some take props. `<Multiverse ftlmanOnly />` drops a tab. `<Troubleshooting Saves={Saves} />`
passes the page's own platform partial into a shared one, so the save path is named
where it is needed.

Read a partial before editing it, the change shows up on every page that imports it.

Headings inside a partial don't reach the table of contents on their own. Register
any new partial that has one in `src/routeMiddleware.ts`.

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
becomes `de/windows/updating.mdx`. Partials mirror the same way, keeping their group:
`_partials/en/shared/_intro-setup.mdx` becomes `_partials/de/shared/_intro-setup.mdx`.

To see what needs work run:

```sh
npm run check:stale
```

It lists, per language, every page and partial that is either **missing** or **outdated**.

Outdated meaning the English file has been committed to more recently than its translation.
