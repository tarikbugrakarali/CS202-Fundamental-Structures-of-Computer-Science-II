/*
* Title: BinaryNode
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 2
*/

#ifndef BinaryNode_h
#define BinaryNode_h

#include <stdio.h>
#include <stddef.h>

class BinaryNode{
public:
     int item;
    BinaryNode *leftChildPtr;
    BinaryNode *rightChildPtr;
private:
    // instance variables


    // default constructor
    BinaryNode();
    BinaryNode(const int &nodeItem);
    BinaryNode(const int &nodeItem, BinaryNode *left , BinaryNode *right );

    BinaryNode* getLeftChildPtr() const;
    BinaryNode* getRightChildPtr() const;
    int getItem() const;
    void setItem(const int &nodeItem);

    void setLeftChildPtr(BinaryNode * leftPtr);
    void setRightChildPtr(BinaryNode * rightPtr);


    friend class BinarySearchTree;
};

#endif
