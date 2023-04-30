/*
* Title: RequestArray
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: RequestArray Implementation which takes  the request from txt and save it in array.
*/
#include <iostream>
#include "RequestArray.h"
#include <sstream>
using namespace std;

RequestArray ::RequestArray( string filename){

    ifstream dosyaOku(filename.c_str());
    string satir = "";
    int counter = -1;

    if ( dosyaOku.is_open() ){

        while ( getline(dosyaOku, satir) ){
            counter ++;
        }
        reqNo = counter;
        dosyaOku.close();
    }

    arr = new KeyedItem[counter];
    string *lines = new string[counter + 1];
    string line = "";
    ifstream read(filename.c_str());
    int i = 0;

    if ( read.is_open() ){

        while ( getline(read, line) ){
            lines[i] = line;
            i++;
        }
        read.close();
    }

    for(int j = 1; j < counter+1; j ++)
    {

        string *tokens = new string[4];
        stringstream check1(lines[j]);
        string intermediate;
        int k = 0;

        while(getline(check1, intermediate, ' '))
        {
            tokens[k] = intermediate;
            k ++;
        }

        for(int i = 0; i < 4; i++)
        {
            stringstream geek(tokens[i]);
            int x = 0;
            geek >> x;

            if(i == 0)
                arr[j-1].setId(x);

            else if(i == 1)
                arr[j-1].setPriority(x);

            else if(i == 2)
                arr[j-1].setRequestTime(x);

            else
                arr[j-1].setProcessTime(x);
        }

    }
}

KeyedItem* RequestArray::getArr()
{
    return arr;
}

int RequestArray::getReqNo()
{
    return reqNo;
}

