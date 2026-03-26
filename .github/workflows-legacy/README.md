# Legacy Workflows

These workflows have been replaced by the new modular release system.

## Replaced Workflows

- **release.yml**: Old monolithic release workflow (bump + build + release in one)
- **release-only.yml**: Tag-triggered release workflow

## New System

The new release system splits the process into:
- **release-prepare.yml**: Bump version, create tag, trigger builds
- **release-linux-windows.yml**: Build Linux & Windows platforms
- **release-macos.yml**: Build macOS platform

See `.github/workflows/` for the new workflows.
