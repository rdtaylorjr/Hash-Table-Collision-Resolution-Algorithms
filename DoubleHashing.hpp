/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file DoubleHashing.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#ifndef DoubleHashing_hpp
#define DoubleHashing_hpp

#include "Hash.hpp"

template <typename Key, typename Value>
class DoubleHashing : public Hash<Key, Value> {
public:
    /**
     Constructor
     @param initialSize the initial size of the hash table
     @param doubleFactor factor R to be used in double hashing
     */
    DoubleHashing(int initialSize, int doubleFactor);
    
    /**
     Destructor
     */
    virtual ~DoubleHashing();
    
protected:
    /**
     Looks up a key in the hash table
     @param key the key
     @return the index of the key in the hash table
     */
    virtual int lookUp(const Key& key);

private:
    int doubleFactor;
    
    /**
     Hashes the key a second time
     @param key the key
     @return the hashed key
     */
    int hash2(const Key& key);
};

#include "DoubleHashing-impl.hpp"

#endif /* DoubleHashing_hpp */
