#include <iostream>
#include "sorting.h"
using namespace std;
int main() {

    // selection
    cout << "Selection Sort " << endl;
    int compCount = 0;
    int moveCount = 0;
    int arrayTest[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    selectionSort(arrayTest, 16, compCount, moveCount);
    displayArray(arrayTest, 16);

    // selection
    cout << "Merge Sort " << endl;
    compCount = 0;
    moveCount = 0;
    int arrayTest1[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    mergeSort(arrayTest1, 16, compCount, moveCount);
    displayArray(arrayTest1, 16);

    // selection
    cout << "Quick Sort " << endl;
    compCount = 0;
    moveCount = 0;
    int arrayTest3[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    quickSort(arrayTest3, 16, compCount, moveCount);
    displayArray(arrayTest3, 16);

    // radix
    cout << "Radix Sort " << endl;
    compCount = 0;
    moveCount = 0;
    int arrayTest2[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    radixSort(arrayTest2, 16);
    displayArray(arrayTest2, 16);

    performanceAnalysis();
}
