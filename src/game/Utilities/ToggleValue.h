#pragma once

template <typename T>
struct ToggleValue
{
    T value;
    bool enabled = false;

    ToggleValue()
    {
        enabled = false;
    }

    ToggleValue(const T val)
    {
        value = val;
        enabled = true;
    }

    void operator=(const T val)
    {
        value = val;
        enabled = true;
    }
};
