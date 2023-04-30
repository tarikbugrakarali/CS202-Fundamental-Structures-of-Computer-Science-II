/*
* Title: PriorityQueue
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: PriorityQueue Implementation
*/
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H



#include "Heap.h"
typedef HeapItemType PQItemType;

class PriorityQueue
{
public:
    PriorityQueue();
    PriorityQueue( int newSize);
    ~PriorityQueue();

    bool pqIsEmpty() const;
    void pqInsert( const PQItemType& newItem);
    void pqDelete( PQItemType& priorityItem);
    KeyedItem getHead();


private:
    Heap* h;
};

#endif // PRIORITYQUEUE_H
