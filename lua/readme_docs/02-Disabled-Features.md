# Disabled Features

## Standard Lua Libraries

- `package` is unavailable
  - `require` is currently unavailable but an implementation will be added later
- `math.random` is currently disabled
- `math.randomseed` is removed and will not be re-added since we will use FTL's internal seed
- `os` is disabled entirely
- `coroutine` is disabled entirely, we might consider allowing it if a need is demonstrated and we can prove multithreading would not be dangerous to FTL
- `io` is disabled entirely
- `debug` is disabled entirely because too many of its functions are dangerous

## Disabled features of Lua Basic library
Specifically the following methods are **disabled**:
 
 - `collectgarbage`
 - `dofile`
 - `load`
 - `loadfile`

## Additional libraries

- We will add `serpent.lua` but it's not yet added
