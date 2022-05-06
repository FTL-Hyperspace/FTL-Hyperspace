# Planned Features

### Upcoming
- Ability to load separate lua files for sanity & organizational sake
- Ability to call various draw & image methods to make your own graphics *nightmare*, AS-IS with no warranty.
- Ability to listen to events
  - First planned events related to UI actions & weapons but we'll see what works.
- Ability to replace the CrewAI with a custom implementation
- Change the active player's vessel to a different blueprint
- Ability to remove systems from an active vessel
- Joke about blowing up engine (engin ovahrdrive capcitor mak free+) could blow up your engines (remove them) or your "computer control" of your engines resuling in random jumps (intercept jump button & jump to a random node, after so many jumps jump to next sector)

### Far Future
- Ability to save any data to a run using `currentRun`, you can save any data variable to `currentRun.whateverNameYouLike` and it will be reloaded with each run
- Ability to save any data across runs using `profile`, you can save any data variable to `profile.whateverNameYouLike` and it will persist across runs.
- XML generation (xml library) in Lua for passing custom blueprints on-the-fly (random weapon generator? ship editor?)
