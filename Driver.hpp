/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Driver.hpp
 @author Russell Taylor
 @date 9/9/20
*/

#ifndef Driver_hpp
#define Driver_hpp

#include <fstream>
#include "LinearProbing.hpp"
#include "QuadraticProbing.hpp"
#include "DoubleHashing.hpp"

class Driver {
public:
    /**
     Opens file and calls methods to test hashing
     @param ifname the input filename
     @param ofname the output filename
     */
    void testFile(const string& ifname, const string& ofname);
    
private:
    ofstream fout;
    vector<int> data;
    const int tableSize = 191;
    const int doubleFactor = 181;
    
    /**
     Reads data from input file
     @param ifname the input file name
     */
    void readData(const string& ifname);
    
    /**
     Tests the hash table methods
     @param description a description of the sort order of the data
     */
    void testData(const string& description);
    
    /**
     Inputs a key into the hash table
     @param key the key
     @param lp a linear probing object
     @param qp a quadratic probing object
     @param dh a double hashing object
     */
    void testInputKey(const int key, Hash<int, int>& lp, Hash<int, int>& qp, Hash<int, int>& dh);
    
    /**
     Test the key value
     @param description a description of the collision resolution strategy
     @param hashTable a hash table object
     @param key the key
     @param value the value
     */
    void testKeyValue(string description, Hash<int, int>& hashTable, const int key, const int value);
};

#endif /* Driver_hpp */
