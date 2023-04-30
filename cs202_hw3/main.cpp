#include <iostream>
#include "Heap.h"
#include "PriorityQueue.h"
#include "RequestArray.h"
#include "Simulator.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char** argv){
    std::stringstream f(argv[2]);
    string str;
    double avr;
    f >> avr;
    str = std::string(argv[1]);
    Simulator simulator(avr, str );

    return 0;

}
