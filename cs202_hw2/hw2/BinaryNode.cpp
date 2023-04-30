/*
* Title: BinaryNode
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 2
*/
#include "BinaryNode.h"
#include <stddef.h>
// Default constructor
BinaryNode::BinaryNode(){};

// Constructor
BinaryNode::BinaryNode(const int &nodeItem, BinaryNode *left, BinaryNode *right){
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    }
BinaryNode::BinaryNode(const int &nodeItem){
    item = nodeItem;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    }
BinaryNode* BinaryNode:: getLeftChildPtr() const{

   return leftChildPtr;
}

BinaryNode* BinaryNode::getRightChildPtr() const{

   return rightChildPtr;
}

void BinaryNode::setLeftChildPtr(BinaryNode * leftPtr){
   leftChildPtr = leftPtr;
}
void BinaryNode::setRightChildPtr(BinaryNode * rightPtr){
  rightChildPtr = rightPtr;
}

int BinaryNode::getItem() const{
  return item;
}
void BinaryNode::setItem(const int &nodeItem){
 item = nodeItem;
}
