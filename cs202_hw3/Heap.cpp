/*
* Title: Heap
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: Heap Implementation
*/
#include "Heap.h"

Heap::Heap()
{
    size = 0;
    newSize = 0;
}

Heap::Heap( int sizeNew)
{
    newSize = sizeNew;
    items = new HeapItemType[newSize];
    size = 0;
}

Heap::~Heap()
{
    delete [] items;
}

bool Heap::heapIsEmpty() const
{
    return (size == 0);
}

void Heap::heapInsert( const HeapItemType& newItem)
{
    if( size >= newSize)
        cout << "Heap is full" << endl;
    items[size] = newItem;

    int place = size;
    int parent = (place - 1)/2;

    while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority()))
    {
        HeapItemType temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}

void Heap::heapDelete( HeapItemType& rootItem)
{
    if( heapIsEmpty())
        cout << "Heap is empty!" << endl;


    else
    {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root)
{
    int child = 2 * root + 1;

    if( child < size)
    {
        int rightChild = child + 1;

        if( (rightChild < size) && ((items[rightChild].getPriority() > items[child].getPriority()) || (items[rightChild].getPriority() == items[child].getPriority() && items[rightChild].getId() < items[child].getId())))
            child = rightChild;

        if( (items[root].getPriority() < items[child].getPriority()) || (items[root].getPriority() == items[child].getPriority() && items[root].getId() > items[child].getId()))
        {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild( child);
        }
    }
}

KeyedItem Heap:: getHead()
{
    return items[0];
}
