/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file QuadraticProbing-impl.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#include "QuadraticProbing.hpp"

/**
 Constructor
 @param initialSize the initial size of the hash table
 */
template <typename Key, typename Value>
QuadraticProbing<Key, Value>::QuadraticProbing(int initialSize) {
    this->table.resize(initialSize);
    this->collisions = 0;
}

/**
 Destructor
 */
template <typename Key, typename Value>
QuadraticProbing<Key, Value>::~QuadraticProbing() {
    for (const auto p : this->table)
        delete p;
}

/**
 Looks up a key in the hash table
 @param key the key
 @return the index of the key in the hash table
 */
template <typename Key, typename Value>
int QuadraticProbing<Key, Value>::lookUp(const Key& key) {
    const int startIndex = this->hashIndex(key);
    int index = startIndex, i = 0;

    while (true) {
        const Record<Key, Value> *p = this->table[index];
        if (p == nullptr || p->key == key)
            return index;

        this->collisions += 1;
        i += 1;
        index = startIndex + i * i;
        index %= this->table.size();

        if (index == startIndex)
            return int(this->table.size()) + 1;
    }
}
