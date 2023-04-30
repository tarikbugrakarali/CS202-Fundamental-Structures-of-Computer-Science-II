/*
* Title: KeyedItem
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: KeyedItem Implementation
*/
#ifndef KEYEDITEM_H
#define KEYEDITEM_H

typedef int KeyType;

class KeyedItem
{
public:
    KeyedItem();
    KeyedItem( const KeyType& newID, const KeyType& newPriority, const KeyType& newReqTime, const KeyType& newProTime);
    ~KeyedItem();

    void setId( int newID);
    void setPriority( int newPriority);
    void setRequestTime( int newReqTime);
    void setProcessTime( int newProTime);
    KeyType getId() const;
    KeyType getPriority() const;
    KeyType getRequestTime() const;
    KeyType getProcessTime() const;

private:
    KeyType id;
    KeyType priority;
    KeyType requestTime;
    KeyType processTime;
};

#endif // KEYEDITEM_H
