// Name:Keying Zhou
// Loginid:1935-0418-72
// CSCI 455 PA5
// Spring 2017


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
// utility functions used by this code


void append (ListType &list, const string &theKey, int theValue)
{
    Node * p = list;
    if (list == NULL) {                             //if it is an empty list, add a node to the list
        list = new Node(theKey, theValue, list);    // the pointer of the list point to the first node
        return;
    }
    while (p->next != NULL) {       //if the list is not empty, move the pointer to the end of the list
        p = p->next;
    }
    p->next = new Node(theKey, theValue);            //add a node at the end of the list
}

int * contain(ListType &list, const string &theKey){
    Node *p = list;
    while(p != NULL){
        if (theKey == p->key){
            return & p->value;         //if find the key in the list, return the address of that value
        }
        p = p->next;                  //traverse the list to find the key
    }
    return NULL;                       // if the key is not in this list, return null
}

void printList(ListType &list){
    Node *p = list;
    while(p != NULL){
        string key = p->key;
        int value = p->value;
        cout << key << " " << value << endl;
        p = p->next;
    }
}

bool listRemove(ListType &list, string target){
    Node * p = list;
    if (list != NULL){
        if(target == list->key){                //if the first node is the target
            if (list->next != NULL){            //if the node is not the only node in the list
                Node * temp = list;             //delete the node and move the pointer to
                list = list->next;              //the next node in the list
                delete temp;
            }else{
                delete list;                   //if the node is the only node in the list,
                list = NULL;                   //just delete the node and pointer to the list is NULL
            }
            return true;
        }
        while(p->next != NULL){                 //if the first node is not the target
            if(target == p->next->key){
                Node * temp = p->next;
                p-> next = p->next->next;       //the next pointer of the previous node of target
                delete temp;                    //should point to the next node of target now
                return true;
            }else{
                p = p->next;
            }
        }
    }
    return false;
}

int countNodes(ListType &list){
    Node *p = list;
    int result = 0;
    while(p != NULL){
        result++;
        p = p->next;
    }
    return result;
}

// add definitions for your private methods here



