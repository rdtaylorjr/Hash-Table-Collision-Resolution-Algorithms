/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Driver.cpp
 @author Russell Taylor
 @date 9/9/20
*/

#include <iostream>
#include "Driver.hpp"

/**
 Opens file and calls methods to test hashing
 @param ifname the input filename
 @param ofname the output filename
 */
void Driver::testFile(const string& ifname, const string& ofname) {
    cout << "Input file " << ifname << ", output file " << ofname << "\n";

    readData(ifname);
    fout.open(ofname);
    
    testData("Random Order");

    sort(data.begin(), data.end());
    testData("Ascending Order");
    
    sort(data.begin(), data.end(), greater<int>());
    testData("Descending Order");
    
    data.clear();
    fout.close();

    cout << "Done\n";
}

/**
 Reads data from input file
 @param ifname the input file name
 */
void Driver::readData(const string& ifname) {
    ifstream fin(ifname);
    int key;

    while (fin >> key)
        data.push_back(key);

    fin.close();
}

/**
 Tests the hash table methods
 @param description a description of the sort order of the data
 */
void Driver::testData(const string& description) {
    fout << "*** " << description << " Start *** " << "\n\n";
 
    LinearProbing<int, int> lp(tableSize);
    QuadraticProbing<int, int> qp(tableSize);
    DoubleHashing<int, int> dh(tableSize, doubleFactor);

    for (auto& key : data)
        testInputKey(key, lp, qp, dh);

    fout << "Linear    " << lp.getCollisions() << " collisions\n";
    fout << "Quadratic " << qp.getCollisions() << " collisions\n";
    fout << "Double    " << dh.getCollisions() << " collisions\n";

    fout << "\n*** " << description << " End *** " << "\n\n";
}

/**
 Inputs a key into the hash table
 @param key the key
 @param lp a linear probing object
 @param qp a quadratic probing object
 @param dh a double hashing object
 */
void Driver::testInputKey(const int key, Hash<int, int>& lp, Hash<int, int>& qp, Hash<int, int>& dh) {
    const int value = key * 2;

    testKeyValue("Linear   ", lp, key, value);
    testKeyValue("Quadratic", qp, key, value);
    testKeyValue("Double   ", dh, key, value);

    fout << "\n";
}

/**
 Test the key value
 @param description a description of the collision resolution strategy
 @param hashTable a hash table object
 @param key the key
 @param value the value
 */
void Driver::testKeyValue(string description, Hash<int, int>& hashTable, const int key, const int value) {
    
    const int previousCollisions = hashTable.getCollisions();

    hashTable.put(key, value);

    const int* retrievedValue = hashTable.get(key);
    const string& retrievedText = retrievedValue != nullptr ? to_string(*retrievedValue) : "null";

    fout << key << " : " << value << " -> " << retrievedText << ", collisions " << (hashTable.getCollisions() - previousCollisions) << "\n";

    if (retrievedValue == nullptr || *retrievedValue != value) {
        fout << "Retrieved value " << retrievedText << " does not match stored value " << value << " for key " << key << "\n";
        throw runtime_error("value mismatch");
    }
}
