#pragma once

// Sets variable to value while action runs, then puts the previous value back.
// For state a hook reads because the hooked function can't take it as an argument.
template <typename T, typename V, typename Action>
void RunWithValue(T &variable, V &&value, Action action)
{
    T old = variable;
    variable = value;
    action();
    variable = old;
}
