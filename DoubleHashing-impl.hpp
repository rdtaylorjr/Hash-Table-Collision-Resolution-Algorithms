/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file DoubleHashing-impl.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#include "DoubleHashing.hpp"

/**
 Constructor
 @param initialSize the initial size of the hash table
 @param doubleFactor factor R to be used in double hashing
 */
template <typename Key, typename Value>
DoubleHashing<Key, Value>::DoubleHashing(int initialSize, int doubleFactor) {
    this->table.resize(initialSize);
    this->collisions = 0;
    this->doubleFactor = doubleFactor;
}

/**
 Destructor
 */
template <typename Key, typename Value>
DoubleHashing<Key, Value>::~DoubleHashing() {
    for (const auto p : this->table)
        delete p;
}

/**
 Looks up a key in the hash table
 @param key the key
 @return the index of the key in the hash table
 */
template <typename Key, typename Value>
int DoubleHashing<Key, Value>::lookUp(const Key& key) {
    const int startIndex = this->hashIndex(key);
    int index = startIndex, i = 0;

    while (true) {
        const Record<Key, Value> *p = this->table[index];
        if (p == nullptr || p->key == key)
            return index;

        this->collisions += 1;
        i += 1;
        index = (i * hash2(key) + startIndex) % this->table.size();

        if (index == startIndex)
            return int(this->table.size()) + 1;
    }
}

/**
 Hashes the key a second time
 @param key the key
 @return the hashed key
 */
template <typename Key, typename Value>
int DoubleHashing<Key, Value>::hash2(const Key& key) {
    const int index = this->hash(key);
    return doubleFactor - (index % doubleFactor);
}
