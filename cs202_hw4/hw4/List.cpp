/*
* Title: List
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 4
* Description : A LinkedList implementation
*/

#include "List.h"     // header file
#include <cstddef>     // for NULL
using namespace std;
List::List(): size(0), head(NULL){

}
List::~List(){

   while (!isEmpty())
      remove(1);

} // end destructor
bool List::isEmpty() const{

   return size == 0;

}  // end isEmpty
int List::getLength() const{

   return size;

}  // end getLength
Node *List::find(int index) const{
// Locates a specified node in a linked list.
// Precondition: index is the number of the
// desired node.
// Postcondition: Returns a pointer to the
// desired node. If index < 1 or index > the
// number of nodes in the list, returns NULL.

   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else{ // count from the beginning of the list
      Node *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  // end find

bool List::insert(int index, string newItem, int line) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   Node *newPtr = new Node;
   size = newLength;
   newPtr->setWord(newItem); ;
   newPtr->setLine(line);

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      Node *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} // end insert

bool List::add(string newItem, int line){
   int newLength = getLength() + 1;
   int index = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   Node *newPtr = new Node;
   size = newLength;
   newPtr->setWord(newItem); ;
   newPtr->setLine(line);

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      Node *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;
}

bool List::remove(int index) {

   Node *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;
      head = head->next;
   }
   else{
      Node *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;

   return true;

}  // end remove

void List::printList()
{
    Node* n = head;
    while (n != NULL) {
        cout << n->getWord() << "\n";
        n = n->next;
    }
    cout<<endl;
}

void List::printBack()
{
    Node* n = head;
    string *arr = new string [size];
    int counter = 0;

    while (n != NULL) {
        arr[counter] =  n->getWord();
        n = n->next;
        counter ++;
    }

    for(int i = size - 1; i > -1; i--)
        cout<< arr[i] <<endl;
}

Node* List:: searchList(string target){
    Node* n = head;
    Node* emp = new Node;
    while (n != NULL) {
        if(n->getWord().compare(target) == 0)
            return n;

        n = n->next;
    }
    cout<<"NOT FOUND"<<endl;
    return NULL;
}

Node* List:: searchHash(int target){
    Node* n = head;
    Node* emp = new Node;
    while (n != NULL) {
        if(n->getHashNo() == target)
            return n;

        n = n->next;
    }
    cout<<"NOT FOUND"<<endl;
    return NULL;
}

Node* List:: searchLine(int target){
    Node* n = head;
    Node* emp = new Node;
    while (n != NULL) {
        if(n->getLine() == target)
            return n;

        n = n->next;
    }
    cout<<"NOT FOUND"<<endl;
    return NULL;
}


