/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Hash-impl.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#include "Hash.hpp"
using namespace std;

/**
 Gets the value corresponding to a given key
 @param key the key
 @return the corresponding value
 */
template <typename Key, typename Value>
Value* Hash<Key, Value>::get(const Key& key) {
    int index = lookUp(key);
    if (index > table.size())
        return nullptr;

    Record<Key, Value> *p = table[index];
    return p ? &(p->value) : nullptr;
}

/**
 Puts a key-value pair into the hash table
 @param key the key
 @param value the value
 */
template <typename Key, typename Value>
void Hash<Key, Value>::put(const Key& key, const Value& value) {
    int index = lookUp(key);
    if (index > table.size())
        throw runtime_error("Table is full");

    Record<Key, Value> *p = table[index];
    if (p == nullptr)
        table[index] = new Record<Key, Value>(key, value);
    else
        p->value = value;
}

/**
 Gets the number of collisions
 @return the number of collisions
 */
template <typename Key, typename Value>
int Hash<Key, Value>::getCollisions() const {
    return collisions;
}


/**
 Hash index
 @param key the key
 @return the hash index of the key
 */
template <typename Key, typename Value>
int Hash<Key, Value>::hashIndex(const Key& key) const {
    const int index = hash(key);
    
    return index % table.size();
}

/**
 Scrambles the key via bitwise operations
 @param key the key
 @return the hashed key
 */
template <typename Key, typename Value>
int Hash<Key, Value>::hash(const Key& key) {
    return (key >> 8) | ((key& 0xff) << 16);
}
