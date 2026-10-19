<!-- PR title: "Fix/Add/Expose + what changes", under 75 characters
     Good: Fix crash when reloading a save with Artillery in the store
           Add repairProgressFix setting to stop Repair Burst storing repair progress
           Expose ShipManager::RemoveCrewmember to Lua
     Bad:  Store Artillery Crash Fix / Added repairProgressFix setting / Fix issue #716 -->

Fixes #  <!--(link the issue if exists, remove this line if doesn't) -->

## Why this change is needed
<!-- Bug: the symptom.
     Feature: what it lets players/modders do, and who asked for it (link the issue or discussion). -->

## How this was solved/implemented
<!-- Bug: the root cause, and how this change fixes it.
     Feature: the approach.
     Note any vanilla functions/members you relied on and what they do:
     it saves the reviewer and future you from reverse engineering it again.
     Known limitations or follow-ups: list them here.
     Trivial change? "Obvious from the diff" is fine. -->

## Player / modder facing
<!-- Delete if nothing changes for players or modders. -->
- Setting: <!-- name in hyperspace.xml + default, or "always on" -->
- Gameplay/balance: <!-- what changes and by how much -->
- New XML / Lua API: <!-- tags, attributes, exposed functions -->
- New text: <!-- text ids added, and which languages still need a translation -->
- Docs updated: <!-- wiki page, or "not needed" -->

## Demo
<!-- Features and anything visible in game: a short video or screenshots, ideally before/after.
     Delete for non-visual changes (build, CI, internals). -->

## Testing

**Steps to reproduce:**
1.

**Before:** <!-- what happened without this change -->

**After:** <!-- what happens now -->

**Test files/mods:** <!-- test mod, save or Lua snippet you used, and any overhaul mod required for it -->

Tested on:
- [ ] Windows
- [ ] Linux
- [ ] macOS

## Risk
- [ ] Changes vanilla behavior <!-- if checked: must be a hyperspace.xml setting, disabled by default -->
- [ ] Rewrites a vanilla function <!-- which one. Must keep the vanilla behavior it replaces -->
- [ ] New or changed hook signatures, ZHL or struct layouts
- [ ] Changes something already exposed to Lua, or existing XML tags / setting defaults <!-- breaks mods that use it -->
- [ ] Affects save files (new fields, changed format)

<!-- If review changes the approach, update this description to match. -->
