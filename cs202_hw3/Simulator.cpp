/*
* Title: Simulator
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 3
* Description: Simulator Implementation which find optimum number of printer and simulate it.
*/
#include "Simulator.h"
using namespace std;



Simulator::Simulator(double averageTime,string file)
{
    theFile = file;

    av = (double)averageTime;

    int nP;
    nP = findNumberOfPrinter();

    run(nP);
}

Simulator::~Simulator()
{
    //dtor
}

//Calculate the average time for given number of printer
double Simulator:: ProcessedTime(int printerNumber ){

    RequestArray r(theFile);
    KeyedItem *arr = r.getArr();
    requestNum = r.getReqNo();

    PriorityQueue* pq = new PriorityQueue(requestNum);
    times = new int[printerNumber];
    for(int i = 0; i < printerNumber; i++)
        times[i] = 0;
    time = 0;
    double average = 0.0;

    while(time < 100)
    {
        for(int i = 0; i < requestNum; i++ )
        {

            if(arr[i].getRequestTime() == time)
            {
                pq ->pqInsert(arr[i]);
            }
        }

        for(int k = 0; k < printerNumber; k++)
        {

            if(!(pq->pqIsEmpty()))
            {

                if(times[k] == 0)
                      times[k] = pq->getHead().getRequestTime();

                if(time == times[k])
                {

                   average = average + (double)(time - pq->getHead().getRequestTime());
                   times [k] = times [k] +  pq->getHead().getProcessTime();
                   pq->pqDelete(arr[k]);
                }
            }

        }

        time++;

    }

    delete []times;
    delete pq;
    delete []arr;

    return ( average / requestNum );
}

//determine the optimal number of printer
int Simulator::findNumberOfPrinter()
{
    int no = 1;
    bool check = true;
    while (check){


        if(av >= ProcessedTime(no))
            check = false;

        no ++;
    }


    cout<<"Minimum number of printers required: "<<no -1 <<endl;
    return no-1;
}

//Run the simulation with optimal number of printer
void Simulator:: run(int printerNumber ){

    cout<<"Simulation with "<< printerNumber <<" printers:"<<endl;
    RequestArray r(theFile);
    requestNum = r.getReqNo();
    KeyedItem *arr = r.getArr();
    PriorityQueue* pq = new PriorityQueue(requestNum);
    times = new int[printerNumber];
    for(int i = 0; i < printerNumber; i++)
        times[i] = 0;
    time = 0;
    double average = 0.0;

    while(time < 100)
    {
        for(int i = 0; i < requestNum; i++ )
        {

            if(arr[i].getRequestTime() == time)
            {

                pq ->pqInsert(arr[i]);

            }
        }

        for(int k = 0; k < printerNumber; k++)
        {

            if(!(pq->pqIsEmpty()))
            {

                if(times[k] == 0)
                      times[k] = pq->getHead().getRequestTime();

                if(time == times[k])
                {

                   cout << "Printer "<<k<< " print request "<< pq->getHead().getId() << " at minute " << time <<  "( wait : "<< time - pq->getHead().getRequestTime()<<" mins )"<< endl;
                   average = average + (double)(time - pq->getHead().getRequestTime());
                   times [k] = times [k] + pq->getHead().getProcessTime();

                   pq->pqDelete(arr[k]);
                }
            }

        }

        time++;

    }

    delete []times;
    delete pq;
    delete []arr;
    cout<< "Average waiting time: "<<average / requestNum <<" minutes" <<endl;

}
