#pragma once
#include <cassert>
#include <cstdint>
#include <map>

/// An ordered map whose iterators are *never* invalidated, even if a key is
/// deleted.
///
/// Note that these iterators may behave in an unexpected way, as they can
/// be made invalid and then valid again many times throughout their lifetime.
/// Iterators which have been made dead are not dereferencable
/// (technically they are but don't rely on this, we may want to run the destructor earlier)
/// but can be incremented as usual.
/// Modifications to the map are immediately made visible to any currently live iterators,
/// this means that additions will be seen by any iterators *that are currently positioned
/// before or on the added element*.
///
/// For example, suppose there is a map with three keys {"a", "c", "e"} currently
/// being iterated with the current position being on "c".
/// If in this iteration two new keys "b" and "d" are added then next iteration
/// will encounter "d" but will not see "b".
template <typename K, typename V> class StableMap {
    constexpr static uint32_t NODE_ZOMBIE_FLAG = 0x80000000;

    struct Node {
        V value;
        uint32_t refcount = 0;

        Node(V &&value) : value(std::move(value)), refcount(0) {}

        void incref() { ++refcount; }
        bool decref() { return --refcount == NODE_ZOMBIE_FLAG; }
        void kill_in(StableMap<K, V> &parent) {
            bool wasAlive = !is_dead();
            refcount |= NODE_ZOMBIE_FLAG;
            parent._numDead += wasAlive;
        }
        void resurrect_in(StableMap<K, V> &parent) {
            bool wasDead = is_dead();
            refcount &= ~NODE_ZOMBIE_FLAG;
            parent._numDead -= wasDead;
        }
        bool is_dead() { return refcount & NODE_ZOMBIE_FLAG; }
    };

    std::map<K, Node> _inner;
    size_t _numDead = 0;

public:
    StableMap() {}
    StableMap(StableMap const &) = delete;
    // Moving this type is very dangerous as there may be Refs currently
    // referring to it.
    StableMap(StableMap &&other) = delete;
    StableMap &operator=(StableMap const &) = delete;
    StableMap &operator=(StableMap &&other) = delete;

    class Ref {
        StableMap<K, V> &_parent;
        typename std::map<K, Node>::iterator _it;

        void decref() {
            if (_it != _parent._inner.end()) {
                if (_it->second.decref()) {
                    _parent._numDead -= 1;
                    _parent._inner.erase(_it);
                }
            }
        }

        void incref() {
            if (_it != _parent._inner.end())
                _it->second.incref();
        }

        Ref(StableMap<K, V> &parent, typename std::map<K, Node>::iterator value)
                : _parent(parent), _it(value) {
            incref();
        }

        friend StableMap<K, V>;

    public:
        Ref(Ref const &other) : _parent(other._parent), _it(other._it) { incref(); }
        Ref(Ref &&other) : _parent(other._parent), _it(other._it) {
            other._it = _parent._inner.end();
        }
        Ref &operator=(Ref const &other) {
            _parent = other._parent;
            _it = other._it;
            incref();
        }
        Ref &operator=(Ref &&other) {
            _parent = other._parent;
            _it = other._it;
            other._it = _parent._inner.end();
        }
        ~Ref() { decref(); }

        operator bool() { return _it != _parent._inner.end() && !_it->second.is_dead(); }
        V &operator*() { return _it->second.value; }
        V const &operator*() const { return _it->second.value; }
        V *operator->() { return &_it->second.value; }
        V const *operator->() const { return &_it->second.value; }
        K const &key() const { return _it->first; }

        void erase() {
            assert(
                    _it != _parent._inner.end() &&
                    "StableMap::Ref::erase called on empty Ref"
            );
            _it->second.kill_in(_parent);
        }

        using iterator_category = std::forward_iterator_tag;
        using value_type = V;
        using pointer = V *;
        using reference = V &;

        Ref &operator++() {
            decref();
            do {
                ++_it;
            } while (_it != _parent._inner.end() && _it->second.is_dead());
            incref();
            return *this;
        }

        Ref operator++(int) {
            Ref ret = *this;
            ++(*this);
            return ret;
        }

        bool operator==(Ref const &other) const { return _it == other._it; }
        bool operator!=(Ref const &other) const { return !(*this == other); }
    };

    void insert_or_assign(K const &key, V &&value) {
        auto it = _inner.find(key);
        if (it != _inner.end()) {
            it->second.value = std::move(value);
            it->second.resurrect_in(*this);
        } else {
            _inner.emplace_hint(it, K(key), Node(std::move(value)));
        }
    }

    Ref insert_if_absent(K const &key, V &&value) {
        auto it = _inner.find(key);
        if (it == _inner.end()) {
            return Ref(*this, _inner.emplace_hint(it, K(key), Node(std::move(value))));
        } else {
            if(it->second.is_dead()) {
                it->second.value = std::move(value);
                it->second.resurrect_in(*this);
            }
            return Ref(*this, it);
        }
    }

    template <typename KeyComparable> Ref find(KeyComparable key) {
        auto it = _inner.find(key);
        if (it != _inner.end())
            return Ref(*this, it);
        else
            return end();
    }

    Ref begin() {
        auto it = _inner.begin();
        while (it != _inner.end() && it->second.is_dead()) {
            ++it;
        }
        return Ref(*this, it);
    }
    Ref end() { return Ref(*this, _inner.end()); }

    size_t size() { return _inner.size() - _numDead; }

    void clear() {
        for (auto it = begin(); it != end(); ++it)
            std::move(it).erase();
        assert(size() == 0 && "StableMap::clear resulted in non-zero size");
    }
};
