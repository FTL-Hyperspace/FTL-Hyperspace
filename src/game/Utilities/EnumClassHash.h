#ifndef ENUMCLASSHASH_H_INCLUDED
#define ENUMCLASSHASH_H_INCLUDED

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

#endif // ENUMCLASSHASH_H_INCLUDED
