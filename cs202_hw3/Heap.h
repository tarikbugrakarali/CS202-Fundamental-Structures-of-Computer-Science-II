/*
* Title: Heap
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: Heap Implementation
*/

#ifndef HEAP_H
#define HEAP_H


#include <iostream>
#include "KeyedItem.h"

using namespace std;

typedef KeyedItem HeapItemType;

class Heap
{
public:
    Heap();
    Heap( int sizeNew);
    ~Heap();

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete( HeapItemType& rootItem);
    KeyedItem getHead();

protected:
    void heapRebuild(int root);

private:
    HeapItemType* items;
    int newSize;
    int size;
};
#endif // HEAP_H
