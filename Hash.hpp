/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Hash.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#ifndef Hash_hpp
#define Hash_hpp

#include <vector>

template <typename Key, typename Value>
struct Record {
    Key key;
    Value value;

    /**
     Constructor
     @param key the record key
     @param value the record value
     */
    Record(const Key& key, const Value& value) {
        this->key = key;
        this->value = value;
    }
};

template <typename Key, typename Value>
class Hash {
public:
    /**
     Gets the value corresponding to a given key
     @param key the key
     @return the corresponding value
     */
    Value* get(const Key& key);

    /**
     Puts a key-value pair into the hash table
     @param key the key
     @param value the value
     */
    void put(const Key& key, const Value& value);

    /**
     Gets the number of collisions
     @return the number of collisions
     */
    int getCollisions() const;

    /**
     Destructor
     */
    virtual ~Hash() { }
    
protected:
    std::vector<Record<Key, Value>*> table;
    int collisions;
    
    /**
     Looks up a key in the hash table
     @param key the key
     @return the index of the key in the hash table
     */
    virtual int lookUp(const Key& key) = 0;
    
    /**
     Returns the hash index of a key
     @param key the key
     @return the hash index of the key
     */
    int hashIndex(const Key& key) const;
    
    /**
     Scrambles the key via bitwise operations
     @param key the key
     @return the hashed key
     */
    static int hash(const Key& key);
};

#include "Hash-impl.hpp"

#endif /* Hash_hpp */
