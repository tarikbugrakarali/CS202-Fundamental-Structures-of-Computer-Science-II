/*
* Title: RequestArray
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: RequestArray Implementation which takes  the request from txt and save it in array.
*/
#ifndef REQUESTARRAY_H
#define REQUESTARRAY_H

#include <iostream>
#include <fstream>
#include <string>
#include"KeyedItem.h"
using namespace std;

class RequestArray {
public:
    RequestArray ( string filename);
    KeyedItem* getArr();
    int getReqNo();

private:
    KeyedItem * arr;
    int reqNo;

};

#endif // REQUESTARRAY_H
