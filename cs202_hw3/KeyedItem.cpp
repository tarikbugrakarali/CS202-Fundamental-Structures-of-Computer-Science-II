/*
* Title: KeyedItem
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: KeyedItem Implementation
*/
#include "KeyedItem.h"

KeyedItem::KeyedItem()
{

}

KeyedItem::KeyedItem( const KeyType& newID, const KeyType& newPriority, const KeyType& newReqTime, const KeyType& newProTime)
{
    id = newID;
    priority = newPriority;
    requestTime = newReqTime;
    processTime = newProTime;
}

KeyedItem::~KeyedItem()
{

}

void KeyedItem::setId( int newID)
{
    id = newID;
}

void KeyedItem::setPriority( int newPriority)
{
    priority = newPriority;
}

void KeyedItem::setRequestTime( int newReqTime)
{
    requestTime = newReqTime;
}

void KeyedItem::setProcessTime( int newProTime)
{
    processTime = newProTime;
}

KeyType KeyedItem::getId() const
{
    return id;
}

KeyType KeyedItem::getPriority() const
{
    return priority;
}

KeyType KeyedItem::getRequestTime() const
{
    return requestTime;
}

KeyType KeyedItem::getProcessTime() const
{
    return processTime;
}
