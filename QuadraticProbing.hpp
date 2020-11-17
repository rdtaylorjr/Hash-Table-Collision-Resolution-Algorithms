/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file QuadraticProbing.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#ifndef QuadraticProbing_hpp
#define QuadraticProbing_hpp

#include "Hash.hpp"

template <typename Key, typename Value>
class QuadraticProbing : public Hash<Key, Value> {
public:
    /**
     Constructor
     @param initialSize the initial size of the hash table
     */
    QuadraticProbing(int initialSize);
    
    /**
     Destructor
     */
    virtual ~QuadraticProbing();
    
protected:
    /**
     Looks up a key in the hash table
     @param key the key
     @return the index of the key in the hash table
     */
    virtual int lookUp(const Key& key);
};

#include "QuadraticProbing-impl.hpp"

#endif /* QuadraticProbing_hpp */
