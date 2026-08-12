/**
 * GitHub Pages serves the site at https://<owner>.github.io/<repo>.
 * CI provides GITHUB_REPOSITORY; outside CI the site serves from the root.
 * SITE_BASE overrides the base completely.
 */
const [owner, repo] = (process.env.GITHUB_REPOSITORY ?? '').split('/');

export const SITE = owner ? `https://${owner.toLowerCase()}.github.io` : 'http://localhost:4321';
export const BASE = process.env.SITE_BASE ?? (repo ? `/${repo}` : '/');
