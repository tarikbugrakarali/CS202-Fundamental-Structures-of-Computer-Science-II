/*
* Title: List
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 4
* Description : A LinkedList implementation
*/
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;
class List{

// constructors and destructor:
public:
   List();                  // default constructor
   List(const List& aList); // copy constructor
   ~List();                 // destructor
   bool isEmpty() const;
   int getLength() const;
   bool insert(int index, string newItem, int line);
   bool add(string newItem, int line);
   bool remove(int index);
   void printList();
   Node *searchList(string target);
   Node *searchHash(int target);
   Node *searchLine(int target);
   Node *find(int index) const;
   void printBack();

private:




   int  size;  // number of items in list
   Node *head;  // pointer to linked list
				    // of items


};

