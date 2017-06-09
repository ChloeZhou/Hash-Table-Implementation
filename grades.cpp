// Name:Keying Zhou
// Loginid:1935-0418-72
// CSCI 455 PA5
// Spring 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

// Update the score for the student in the grade table.
void change(Table * grades, const string &key, int value){
    int * score = grades->lookup(key);        //Get the address of the value or NULL if key is not present
    if (score != NULL){
        * score = value;                   //If the student is in the grade table, change to the new score
    }else{
        cout << "This student is not in the grade table." <<endl;
    }
}

// Prints out a brief command summary
void help(){
    cout << "Command Summary: " <<endl;
    cout << "There are total nine commands that you can use. They are insert, change, lookup, remove, print, size, stats, help and quit." <<endl;
    cout << "1. insert name score--Insert the name and score in the grade table." <<endl;
    cout << "2. change name newscore--Change the score for name already exsists in the grade table." << endl;
    cout << "3. lookup name--Lookup the name, and print out his or her score." << endl;
    cout << "4.remove name--Remove this student." << endl;
    cout << "5. print--Prints out all names and scores in the table." << endl;
    cout << "6.size--Prints out the number of entries in the table." << endl;
    cout << "7.stats--Prints out statistics about the hash table at this point." << endl;
    cout << "8.help--Prints out a brief command summary."<< endl;
    cout << "9.quit--Exits the program." << endl;
};

//Insert the student information
void insert(Table * grades, const string &key, int value){
    bool insert = grades->insert(key, value);
    if(!insert){
        cout << "This name is already in the grade table, don't do the insert again." << endl;
    }

}

//Search for a student
void lookup(Table * grades, const string &key){
    int * lookup = grades->lookup(key);
    if (lookup != NULL){
        cout << * lookup << endl;
    }else{
        cout << "The student is not in the table" << endl;
    }
}

//Remove a student
void remove(Table * grades, const string &key){
    bool remove = grades->remove(key);
    if(!remove){
        cout << "This student isn't in the grade table, can't do remove" << endl;
    }
}


int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }

  grades->hashStats(cout);
    // add more code here
    // Reminder: use -> when calling Table methods, since grades is type Table*
    while(true){
        cout << "cmd> ";
        string command;
        string name;
        int newScore;
        cin >> command;
        if (command == "insert"){
            cin >> name >> newScore;
            insert(grades, name, newScore);
        }
        else if (command == "change"){
            cin >> name >> newScore;
            change(grades, name, newScore);
        }
        else if (command == "lookup"){
            cin >> name;
            lookup(grades,name);
        }
        else if (command == "remove"){
            cin >> name;
            remove(grades, name);
        }
        else if (command == "print"){
            grades->printAll();
        }
        else if (command == "size"){
            cout << grades->numEntries() << endl;
        }
        else if (command == "stats"){
            grades->hashStats(cout);
        }
        else if (command == "help"){
            help();
        }
        else if (command == "quit"){
            return 0;
        }
        else {
            cout << "ERROR: invalid command" << endl;
            help();
        }
    }

}
