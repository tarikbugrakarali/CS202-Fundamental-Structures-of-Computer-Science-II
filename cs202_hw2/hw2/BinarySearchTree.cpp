/*
* Title: BinarySearchTree
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 2
*/
#include "BinarySearchTree.h"
#include <iostream>
#include <stddef.h>
#define COUNT 10
using namespace std;
BinarySearchTree::BinarySearchTree():root( nullptr){}
BinarySearchTree::~BinarySearchTree(){}
int BinarySearchTree::getHeightHelper(BinaryNode * subTreePtr) const
{

  if (subTreePtr == nullptr)
     return 0;
  else
    return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper

int BinarySearchTree:: getHeight()
{
    return getHeightHelper(root);
}

bool BinarySearchTree:: doesExists(BinaryNode * start, int data)
{
    if (start == NULL)
        return false;

    if (start->getItem() == data)
        return true;

    bool left = doesExists(start->getLeftChildPtr(), data);
    // node found, no need to look further
    if(left)
        return true;

    bool right = doesExists(start->getRightChildPtr(), data);

    return right;
}

bool BinarySearchTree::contains(const int newEntry)
{
   return doesExists(root,newEntry);
}

int BinarySearchTree:: getNOfNodes(BinaryNode *node)
{
    if (node == NULL)
       return 0;

    int counter = 0;

    if  (node->leftChildPtr && node->rightChildPtr)
       counter++;

    counter = counter + getNOfNodes(node->leftChildPtr) +  getNOfNodes(node->rightChildPtr);
    return counter;
}

int BinarySearchTree:: getNumberOfNodes()
{
    return getNOfNodes(root);
}



bool BinarySearchTree::add( const int newEntry)
{
 bool operation = doesExists(root,newEntry);
 if(operation){
    cout<<newEntry<<" already exist"<<endl;
    return false;
 }
 else {
 insertItem(root, newEntry);
 cout<<"ok"<<endl;
 return true;
 }
} // end add

void BinarySearchTree::searchTreeInsert(const int newItem) {
		insertItem(root, newItem);
}

void BinarySearchTree::insertItem(BinaryNode *& treePtr,
				const int& newItem)  {

		// Position of insertion found; insert after leaf
		if (treePtr == NULL) {
			treePtr = new BinaryNode(newItem, NULL, NULL);
			if (treePtr == NULL)
				return;
		}
		// Else search for the insertion position
		else if (newItem < treePtr->item)
			insertItem(treePtr->leftChildPtr, newItem);
		else
			insertItem(treePtr->rightChildPtr, newItem);
}

void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int& treeItem){

		if (nodePtr->getLeftChildPtr() == NULL) {
			treeItem = nodePtr->getItem();
			BinaryNode *delPtr = nodePtr;
			nodePtr = nodePtr->getRightChildPtr();
			delPtr->setRightChildPtr(NULL); // defense
			delete delPtr;
		}
		else
			processLeftmost(nodePtr->leftChildPtr, treeItem);
}

void BinarySearchTree::deleteNodeItem(BinaryNode *& nodePtr) {
		BinaryNode *delPtr;
		int replacementItem;


		// (1)  Test for a leaf
		if ( (nodePtr->getLeftChildPtr() == NULL) && (nodePtr->getRightChildPtr() == NULL) )
        {
			delete nodePtr;
			nodePtr = NULL;
		}


		// (2)  Test for no left child
		else if (nodePtr->getLeftChildPtr() == NULL){
			delPtr = nodePtr;
			nodePtr = nodePtr->getRightChildPtr();
			delPtr->setRightChildPtr(NULL);
			delete delPtr;
		}
		// (3)  Test for no right child
		else if (nodePtr->getRightChildPtr() == NULL) {
			delPtr = nodePtr;
			nodePtr = nodePtr->getLeftChildPtr();
			delPtr->setLeftChildPtr(NULL) ;
			delete delPtr;
		}


		// (4)  There are two children:
		//      Retrieve and delete the inorder successor
		else {
			processLeftmost(nodePtr->rightChildPtr, replacementItem);
			nodePtr->setItem(replacementItem);
		}

}

void BinarySearchTree::deleteItem(BinaryNode *&treePtr, int searchKey)
{
		if (treePtr == NULL) // Empty tree
			{
			    return;
			}

		// Position of deletion found
		else if (searchKey == treePtr->getItem())
			deleteNodeItem(treePtr);

		// Else search for the deletion position
		else if (searchKey < treePtr->getItem())
			deleteItem(treePtr->leftChildPtr, searchKey);
		else
			deleteItem(treePtr->rightChildPtr, searchKey);
}

void BinarySearchTree:: remove(const int anEntry)
{
    deleteItem(root, anEntry);
}



void BinarySearchTree::levelorderTraverse()
{
    int h = getNodeheight(root);

    if(h == 1)
        cout<< root->getItem() <<endl;

    else{
        for (int i = 1; i <= h; i++)
        printGivenLevel(root, i);
    }

}

void BinarySearchTree:: printGivenLevel(BinaryNode* root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        cout << root->item << " ";

    else if (level > 1)
    {
        printGivenLevel(root->leftChildPtr, level-1);
        printGivenLevel(root->rightChildPtr, level-1);
    }
}


int BinarySearchTree:: getNodeheight(BinaryNode* node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lheight = getNodeheight(node->leftChildPtr);
        int rheight = getNodeheight(node->rightChildPtr);

        if (lheight > rheight)
            return(lheight + 1);
        else
            return(rheight + 1);
    }
}

BinaryNode* BinarySearchTree:: newNode(int data)
{
    BinaryNode* Node = new BinaryNode();
    Node->item = data;
    Node->leftChildPtr = NULL;
    Node->rightChildPtr = NULL;

    return(Node);
}

void BinarySearchTree:: visit(int& anItem) { cout << anItem << endl; }

void BinarySearchTree::preorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			visit(treePtr->item);
			preorder(treePtr->leftChildPtr);
			preorder(treePtr->rightChildPtr);
		}
}

void BinarySearchTree::inorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			inorder(treePtr->leftChildPtr);
			visit(treePtr->item);
			inorder(treePtr->rightChildPtr);
		}
}

void BinarySearchTree::postorder(BinaryNode *treePtr) {
		if (treePtr != NULL) {
			postorder(treePtr->leftChildPtr);
			postorder(treePtr->rightChildPtr);
			visit(treePtr->item);
		}
}

void BinarySearchTree::postorderTraverse()
{
    postorder(root);
}
void BinarySearchTree::inorderTraverse()
{
    inorder(root);
}
void BinarySearchTree::preorderTraverse()
{
    preorder(root);
}

void BinarySearchTree:: mirrorHelp( BinaryNode* node)
{
    if (node == NULL)
        return;
    else
    {
        BinaryNode* temp;

        mirrorHelp(node->leftChildPtr);
        mirrorHelp(node->rightChildPtr);

        temp     = node->leftChildPtr;
        node->leftChildPtr = node->rightChildPtr;
        node->rightChildPtr = temp;
    }
}

void BinarySearchTree::mirror()
{
    mirrorHelp(root);
}

void BinarySearchTree:: rangeDecision(BinaryNode *root, int k1, int k2)
{

    if ( NULL == root )
        return;

    if ( k1 < root->getItem() )
        rangeDecision(root->leftChildPtr, k1, k2);

    if ( k1 <= root->getItem() && k2 >= root->getItem() )
        cout<<root->getItem()<<" ";

    if ( k2 > root->getItem() )
        rangeDecision(root->rightChildPtr, k1, k2);
}

void BinarySearchTree:: span(int a, int b)
{
    rangeDecision(root, a, b);
}

