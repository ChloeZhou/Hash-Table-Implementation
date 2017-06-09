// Name:Keying Zhou
// Loginid:1935-0818-72
// CSCI 455 PA5
// Spring 2017


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.
    
    // append routine
    // PRE: list is a well-formed list
    // POST: list' is same as list, but with item appended
    void append(ListType &list, const string &theKey, int theValue);

    // look up the list and find the key
    // returns the address of the value or NULL if key is not present
    int * contain(ListType &list, const string &theKey);

    //print out all the entries in the list
    void printList(ListType &list);

    //remove the target node in the list
    //returns true if remove the node sucessfully
    //false iff element wasn't present
    bool listRemove(ListType &list, string target);

    //calculate the number of nodes in the list
    //return the number of nodes in the list
    int countNodes(ListType &list);

// keep the following line at the end of the file
#endif
