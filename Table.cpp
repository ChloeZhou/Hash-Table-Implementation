// Name:Keying Zhou
// Loginid:1935-0418-72
// CSCI 455 PA5
// Spring 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
    hashSize = HASH_SIZE;
    data = new ListType[hashSize];
    for(int i = 0; i < hashSize; i++){          //initialize the dynamic array of pointers
        data[i] = NULL;
    }
}


Table::Table(unsigned int hSize) {
    hashSize = hSize;
    data = new ListType[hashSize];
    for(int i = 0; i < hashSize; i++){
        data[i] = NULL;
    }
}


int * Table::lookup(const string &key) {
    int * result = NULL;
    for (int i = 0; i < hashSize; i++){
        result = contain(data[i], key);         //lookup every list of the table
        if(result != NULL){                     //if the return value is not NULL, return the address
            return result;
        }
    }
    return result;                              //if the result is NULL after traversing all the lists
}                                               // return NULL

bool Table::remove(const string &key) {
    for (int i = 0; i < hashSize; i++) {
        if (listRemove(data[i], key)){
            return true;
        }
    }
    return false;
}

bool Table::insert(const string &key, int value) {
    bool result = false;
    if (lookup(key) == NULL){                      //if the key is not in the table
        int index = hashCode(key);                 //calculate the hashcode of it and insert it to
        append(data[index], key, value);           //the coressponding list
        result = true;
        
    }
    return result;
}

int Table::numEntries() const {
    int numOfEntries = 0;
    for (int i = 0; i < hashSize; i++){
        numOfEntries += countNodes(data[i]);
    }
    return numOfEntries;
}


void Table::printAll() const {
    for (int i = 0; i < hashSize; i++){
        printList(data[i]);
    }
}

void Table::hashStats(ostream &out) const {
    cout << "number of buckets: " << hashSize << endl;
    cout << "number of entries: " << numEntries() << endl;
    int longest = 0;
    int count = 0;
    for (int i = 0; i < hashSize; i++){
        if (data[i] != NULL){
            count ++;                                       //if the bucket is not NULL, count this
            int countChain = countNodes(data[i]);           //as a non-empty bucket
            if (longest < countChain){                      //compare the number of nodes in this list
                longest = countChain;                       //with the longest chain so far we find
            }
        }
    }
    cout << "number of non-empty buckets: " << count << endl;
    cout << "longest chain: " << longest << endl;
}

// add definitions for your private methods here
