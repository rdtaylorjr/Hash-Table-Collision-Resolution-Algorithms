/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file LinearProbing.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#ifndef LinearProbing_hpp
#define LinearProbing_hpp

#include "Hash.hpp"

template <typename Key, typename Value>
class LinearProbing : public Hash<Key, Value> {
public:
    /**
     Constructor
     @param initialSize the initial size of the hash table
     */
    LinearProbing(int initialSize);
    
    /**
     Destructor
     */
    virtual ~LinearProbing();
    
protected:
    /**
     Looks up a key in the hash table
     @param key the key
     @return the index of the key in the hash table
     */
    virtual int lookUp(const Key& key);
};

#include "LinearProbing-impl.hpp"

#endif /* LinearProbing_hpp */
