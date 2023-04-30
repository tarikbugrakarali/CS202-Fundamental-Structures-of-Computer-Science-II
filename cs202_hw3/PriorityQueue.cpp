/*
* Title: PriorityQueue
* Author: Tarık Buğra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: PriorityQueue Implementation
*/

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    h = new Heap();
}

PriorityQueue::PriorityQueue( int newSize)
{
    h = new Heap( newSize);
}

PriorityQueue::~PriorityQueue()
{
    while(!h->heapIsEmpty())
    {
        HeapItemType temp;
        h->heapDelete(temp);
    }
    delete h;
}

bool PriorityQueue::pqIsEmpty() const
{
    return h->heapIsEmpty();
}

void PriorityQueue::pqInsert( const PQItemType& newItem)
{
    h->heapInsert( newItem);
}

void PriorityQueue::pqDelete( PQItemType& priorityItem)
{
    h->heapDelete( priorityItem);
}

KeyedItem PriorityQueue::getHead()
{
    return h->getHead();
}
