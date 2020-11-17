/**
 Lab 3 - Linear Probing, Quadratic Probing, and Double Hashing
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file main.cpp
 @author Russell Taylor
 @date 9/9/20
 
 Based on provided pseudocode
 "Write a program that reads numbers from an input file, creates hash tables, inserts the
 numbers into and retrieves them from the hash tables, and outputs counts of collisions
 for linear probing, quadratic probing, and double hashing probing. Calculate the counts
 of collisions separately for the input data, the same data sorted in ascending order, and
 the same data sorted in descending order."
 
 @pre Three input files containing integer keys separated by whitespaces
 @post Three output files containing key-value pairs, retrieved values, and collision counts for each input key, sorted in three ways, and total collision counts for sorting
*/

#include <iostream>
#include "Driver.hpp"

/**
 Controls operation of the program
 */
int main(int argc, const char * argv[]) {
    try {
        Driver driver;
        driver.testFile("in150.txt", "out150.txt");
        driver.testFile("in160.txt", "out160.txt");
        driver.testFile("in170.txt", "out170.txt");
    }
    catch (const exception& ex) {
        cout << "Exception: " << ex.what() << "\n";
    }
    return 0;
}
