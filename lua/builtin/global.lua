--- Lua global functions.

module 'global'

-- luacheck: ignore 121

---
-- Issues an error when  its argument `v` is false.
-- That is, nil or false. otherwise, returns all its arguments.
-- `message` is an error when absent, it defaults to "assertion failed!"
function assert(v , message) end

---
-- @removed
--
function collectgarbage() end

--- @removed
function dofile() end

---
-- Terminates the last protected function called.
-- Returns `message` as the error message.
-- Function `error` never returns.
-- Usually, `error` adds some information about the error position at the
-- beginning of the message. The `level` argument specifies how to get the
-- error position. With level 1 (the default), the error position is where the
-- `error` function was called. Level 2 points the error to where the function
-- that called `error` was called; and so on. Passing a level 0 avoids the
-- addition of error position information to the message.
function error(message , level) end

---
-- A global variable (not a function) that holds the global environment
-- (that is, `_G._G = _G`). Lua itself does not use this variable; changing
-- its value does not affect any environment, nor vice-versa. (Set `__ENV`
-- to change environments in functions)
-- @table _G

---
-- If `object` does not have a metatable, returns nil. Otherwise, if the
-- object's metatable has a `"__metatable"` field, returns the associated
-- value. Otherwise, returns the metatable of the given object.
function getmetatable(object) end

---
-- For iterating over sequences. Returns three values: an iterator function, the table `t`, and 0,
-- so that the construction
--   for i,v in ipairs(t) do *body* end
-- will iterate over the pairs (`1,t[1]`), (`2,t[2]`), ..., up to the
-- first integer key absent from the table.
function ipairs(t) end

--- @removed
-- Loads a chunk.
-- If `ld` is a string, the chunk is this string.
-- If `ld` is a function, load calls it repeatedly to get the chunk pieces. Each call to `ld` must return a
-- string that concatenates with previous results. A return of an empty string, nil, or no value
-- signals the end of the chunk.
-- If there are no syntactic errors, returns the compiled chunk as a function;
-- otherwise, returns nil plus the error message.
-- If the resulting function has upvalues, the first upvalue is set to the value of the global environment or to `env`,
-- if that parameter is given. When loading main chunks, the first upvalue will be the`_ENV` variable (see 2.2).
-- `source` is used as the source of the chunk for error messages and debug information (see 4.9).
-- When absent, it defaults to `ld`, if `ld` is a string, or to "=(load)" otherwise.
-- The string `mode` controls whether the chunk can be text or binary (that is, a precompiled chunk).
-- It may be the string "b" (only binary chunks), "t" (only text chunks), or "bt" (both binary and text).
-- The default is "bt"
function load () end

--- @removed
-- Similar to `load`, but gets the chunk from file `filename`. Or from the
-- standard input, if no file name is given.
function loadfile () end

---
-- Allows a program to traverse all fields of a table. Its first argument is
-- a table and its second argument is an index in this table. `next` returns
-- the next index of the table and its associated value.
--
-- When called with nil
-- as its second argument, `next` returns an initial index and its associated
-- value. When called with the last index, or with nil in an empty table, `next`
-- returns nil.
--
-- If the second argument is absent, then it is interpreted as
-- nil. In particular, you can use `next(t)` to check whether a table is empty.
-- The order in which the indices are enumerated is not specified, *even for
-- numeric indices*. (To traverse a table in numeric order, use a numerical
-- for or the `ipairs` function.)
--
-- The behavior of `next` is *undefined* if, during the traversal, you assign
-- any value to a non-existent field in the table. You may however modify
-- existing fields. In particular, you may clear existing fields.
function next(table , index) end

---
-- For iterating over all key-value pairs of a table.
-- Returns three values: the `next` function, the table `t`, and nil,
-- so that the construction
--   for k,v in pairs(t) do *body* end
-- will iterate over all key-value pairs of table `t`.
-- See function `next` for the caveats of modifying the table during its
-- traversal.
function pairs(t) end

---
-- Calls function `f` with the given arguments in *protected mode*. This
-- means that any error inside `f` is not propagated; instead, `pcall` catches
-- the error and returns a status code. Its first result is the status code (a
-- boolean), which is true if the call succeeds without errors. In such case,
-- `pcall` also returns all results from the call, after this first result. In
-- case of any error, `pcall` returns false plus the error message.
function pcall(f, arg1, ...) end

---
--Prints any number of  values to `stdout`.
-- Uses the `tostring` function to convert them to strings. `print` is not
-- intended for formatted output, but only as a quick way to show a value,
-- typically for debugging. For formatted output, use `string.format`.
-- 
-- You may wish to use @{log} here in Hyperspace instead to log to a file.
function print(...) end

---
-- Checks whether `v1` is equal to `v2`. Does not invoke any
-- metamethod. Returns a boolean.
function rawequal(v1, v2) end

---
-- Gets the real value of `table[index]`. Does not invoke any
-- metamethod. `table` must be a table; `index` may be any value.
function rawget(table, index) end

---
-- Sets the real value of `table[index]` to `value`. Does not invoke any
-- metamethod. `table` must be a table, `index` any value different from nil,
-- and `value` any Lua value.
-- This function returns `table`.
function rawset(table, index, value) end

---
-- Returns all arguments after argument number
-- `index`. Otherwise, `index` must be the string `"#"`, and `select` returns
-- the total number of extra arguments it received.
function select(index, ...) end

---
-- Sets the metatable for the given table. (You cannot change the metatable
-- of other types from Lua, only from C.) If `metatable` is nil, removes the
-- metatable of the given table. If the original metatable has a `"__metatable"`
-- field, raises an error.
-- This function returns `table`.
function setmetatable(table, metatable) end

---
-- Tries to convert its argument to a number. If the argument is already
-- a number or a string convertible to a number, then `tonumber` returns this
-- number; otherwise, it returns nil.
-- An optional argument specifies the base to interpret the numeral. The base
-- may be any integer between 2 and 36, inclusive. In bases above 10, the
-- letter '`A`' (in either upper or lower case) represents 10, '`B`' represents
-- 11, and so forth, with '`Z`' representing 35. In base 10 (the default),
-- the number can have a decimal part, as well as an optional exponent part
-- (see 2.1). In other bases, only unsigned integers are accepted.
function tonumber(e , base) end

---
-- Converts any value to a string in a reasonable format.
-- For complete control of how numbers are converted, use `string.format`.
-- If the metatable of `e` has a `"__tostring"` field, then `tostring` calls
-- the corresponding value with `e` as argument, and uses the result of the
-- call as its result.
function tostring(e) end

---
-- Returns the type of its only argument, coded as a string. The possible
-- results of this function are "
-- `nil`" (a string, not the value nil), "`number`", "`string`", "`boolean`",
-- "`table`", "`function`", "`thread`", and "`userdata`".
function type(v) end

---
-- A global variable (not a function) that holds a string containing the
-- current interpreter version. The current contents of this variable is
-- "`Lua 5.1`".
-- @table _VERSION

---
-- This function is similar to `pcall`, except that you can set a new
-- error handler.
-- `xpcall` calls function `f` in protected mode, using `err` as the error
-- handler. Any error inside `f` is not propagated; instead, `xpcall` catches
-- the error, calls the `err` function with the original error object, and
-- returns a status code. Its first result is the status code (a boolean),
-- which is true if the call succeeds without errors. In this case, `xpcall`
-- also returns all results from the call, after this first result. In case
-- of any error, `xpcall` returns false plus the result from `err`.
function xpcall(f, err) end

--- @removed
-- Loads the given module. The function starts by looking into the
-- `package.loaded` table to determine whether `modname` is already
-- loaded. If it is, then `require` returns the value stored at
-- `package.loaded[modname]`. Otherwise, it tries to find a *loader* for
-- the module.
-- To find a loader, `require` is guided by the `package.loaders` array. By
-- changing this array, we can change how `require` looks for a module. The
-- following explanation is based on the default configuration for
-- `package.loaders`.
-- First `require` queries `package.preload[modname]`. If it has a value,
-- this value (which should be a function) is the loader. Otherwise `require`
-- searches for a Lua loader using the path stored in `package.path`. If
-- that also fails, it searches for a C loader using the path stored in
-- `package.cpath`. If that also fails, it tries an *all-in-one* loader (see
-- `package.loaders`).
-- Once a loader is found, `require` calls the loader with a single argument,
-- `modname`. If the loader returns any value, `require` assigns the returned
-- value to `package.loaded[modname]`. If the loader returns no value and
-- has not assigned any value to `package.loaded[modname]`, then `require`
-- assigns true to this entry. In any case, `require` returns the final value
-- of `package.loaded[modname]`.
-- If there is any error loading or running the module, or if it cannot find
-- any loader for the module, then `require` signals an error.
-- @remark Will be re-added in the future in a limited fashion but disabled for now for security reasons.
function require(modname) end

