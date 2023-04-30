/*
* Title: Simulator
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: Simulator Implementation which find optimum number of printer and simulate it.
*/
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "PriorityQueue.h"
#include "RequestArray.h"

class Simulator
{
    public:
        Simulator( double averageTime,string file);
        virtual ~Simulator();

    double ProcessedTime(int printerNumber );
    int findNumberOfPrinter();
    void  run(int printerNumber );

protected:

private:

    int * times;
    double av;
    int time;
    int requestNum;
    string theFile;

};

#endif // SIMULATOR_H
