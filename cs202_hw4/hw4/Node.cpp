/*
* Title: Node
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 4
* Description : A Node Class which holds word and indices
*/
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;
Node::Node(){
   neighbors = NULL;
   next = NULL;
   line = 0;
   hashNo = -1;

}
Node::Node(string name,int index){
   neighbors = NULL;
   next = NULL;
   word = name;
   line = index;
   hashNo = hashCalculator();

   cout << hashNo;
}

int Node:: hashCalculator(){
   int hashVal = 0;

   for (int i = 0; i < word.length(); i++){
     hashVal = 37 * hashVal + word[i];
   }

   return hashVal;
}



int  Node:: getHashNo(){ return hashNo; }
int  Node:: getLine(){ return line;}
string  Node:: getWord(){return word;}
void Node:: setLine(int no){line = no;}
void Node:: setWord(string newWord){
    word = newWord;
    hashNo = hashCalculator();
    }


