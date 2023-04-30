/*
* Title: BinarySearchTree
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 2
*/
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include "BinaryNode.h"

class BinarySearchTree{
public:
    // default constructor
    BinarySearchTree();
    // destructor free nodes
    ~BinarySearchTree();

    BinaryNode *root;

    bool isEmpty();

    int getHeightHelper(BinaryNode * subTreePtr) const;
    int getHeight();

    bool doesExists(BinaryNode * start, int data);
    bool contains(const int anEntry);

    int getNOfNodes(BinaryNode *node);
    int  getNumberOfNodes();

    bool add( const int newEntry);
    void insertItem(BinaryNode *& treePtr,const int& newItem);
    void searchTreeInsert(const int newItem);

    void processLeftmost(BinaryNode *&nodePtr, int& treeItem);
    void deleteNodeItem(BinaryNode * &nodePtr);
    void deleteItem(BinaryNode * &treePtr, int searchKey);
    void remove(const int anEntry);

    void levelorderTraverse();
    void printGivenLevel(BinaryNode* root, int level);
    int getNodeheight(BinaryNode* node);
    BinaryNode* newNode(int data);

    void  visit(int& anItem);
    void preorder(BinaryNode *treePtr);
    void inorder(BinaryNode *treePtr);
    void postorder(BinaryNode *treePtr);

    void postorderTraverse();
    void inorderTraverse();
    void preorderTraverse();

    void  mirrorHelp( BinaryNode* node);
    void mirror();

    void  rangeDecision(BinaryNode *root, int k1, int k2);
    void  span(int a, int b);

};

#endif
