/*
* Title: Sorting and Algorithm Efficiency
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 1
*/

#include "sorting.h"
using namespace std;

// Selection Sort
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int indexOfLargest(int theArray[], int size) {
  int indexSoFar = 0;
  for (int currentIndex=1; currentIndex<size;++currentIndex)
  {
    if (theArray[currentIndex] > theArray[indexSoFar])
         indexSoFar = currentIndex;
  }
  return indexSoFar;
}

void  selectionSort(int *arr, const int size, int &compCount, int &moveCount){
    for (int last = size-1; last >= 1; --last)
    {

      int largest = indexOfLargest(arr, last + 1);
      swap(arr[largest], arr[last]);
    }

}

void displayArray(int *arr, int size){
    if (arr != NULL) {
        cout << "[";
        for(int i = 0; i < size-1; i++){
            cout << arr[i] << ", ";
        }
        cout << arr[size-1];
        cout << "]" << endl;
    } else {
        cout << "[]" << endl;
    }
}

//Merge Sort

void merge( int theArray[], int first, int mid, int last) {

   int tempArray[30000]; 	// temporary array

   int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   while ( (first1 <= last1) && (first2 <= last2))
   {
      if (theArray[first1] < theArray[first2]) {
         tempArray[index] = theArray[first1];
         ++first1;
      }
      else {
          tempArray[index] = theArray[first2];
          ++first2;
      }

      ++index;
   }

   // finish off the first subarray, if necessary
   while ( first1 <= last1 ){
      tempArray[index] = theArray[first1];
      ++first1;
      ++index;
   }


   // finish off the second subarray, if necessary
   while ( first2 <= last2){
      tempArray[index] = theArray[first2];
      ++first2;
      ++index;
   }
   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];

}

void mergesort(int *arr, int first, int last, int &compCount, int &moveCount){

  if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergesort(arr, first, mid ,compCount, moveCount);

      mergesort(arr, mid+1, last, compCount, moveCount);

      // merge the two halves
      merge(arr, first, mid, last);
   }
}  // end mergesort


void mergeSort(int *arr, int size, int &compCount, int &moveCount){
     mergesort(arr, 0, size-1, compCount, moveCount);
}
//Quick Sort
void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount){

    int pivot = theArray[first];

    moveCount++;

    int lastS1 = first;
    int firstUnknown = first + 1;

    // iterate through the unknown portion of the array
    while (firstUnknown <=  last)
    {
        if (theArray[firstUnknown] < pivot)
        { // belongs to S1
            lastS1++;
            swap(theArray[firstUnknown], theArray[lastS1]);
            moveCount += 3;
        }

        compCount++;
        firstUnknown++;
    }
    // place pivot in proper position and mark its location

    swap(theArray[first], theArray[lastS1]);
    pivotIndex = lastS1;

    moveCount += 3; //for swap

}

void quicksort(int *theArray, int first, int last, int &compCount, int &moveCount){
    int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quicksort(theArray, first, pivotIndex-1, compCount, moveCount);
      quicksort(theArray, pivotIndex+1, last, compCount, moveCount);
   }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount){
    quicksort( arr, 0, size-1, compCount, moveCount);
}

int numDigits(int number){
    int digits = 0;
    if (number < 0){
        digits = 1;
    }
    while (int(number != 0)) {
        number /= 10;
        digits++;
    }
    return digits;
}

int findMax(int *theArray, int size){
    int numberDigit = numDigits(theArray[0]);
    for (int i = 0; i < size; i++) {
        if (numberDigit < numDigits(theArray[i]) ) {
            numberDigit = numDigits(theArray[i]);
        }
    }
    return numberDigit;
}


void radixSort(int *theArray, int size){
    int maxDigit = findMax(theArray, size);
    radixSort(theArray, size, maxDigit);
}

void radixSort(int *theArray, int n, int numDigits){

    for (int j = 0; j < numDigits ; j++) {
        int array[10][n];
        int countArray[10] = {0};

        for (int i = 0; i < n; i++){

            int lastDigit  = ((int)(theArray[i]/pow(10, j)))%10;
            int pos = countArray[((int)(theArray[i]/pow(10, j)))%10];

            array[ lastDigit ][pos] = theArray[i];
            countArray[(int)(theArray[i]/pow(10, j))%10] = pos+1;

        int currentPosition = 0;
        for (int i = 0; i < 10; i++) {
            int current = 0;
            while(current < countArray[i]){
                theArray[currentPosition++] = array[i][current];
                current++;
            }
        }
    }
}
}

void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
	srand((int)time(NULL)); // random assign

	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];

	for (int i = 0; i < size; i++)
	{
		int element = rand() % (10 * size);

		arr1[i] = element;
		arr2[i] = element;
		arr3[i] = element;
		arr4[i] = element;
	}
}

void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
   srand((int)time(NULL)); // random assign

	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];
	int i = 0;
	int base = rand() % 5;
	int element = base;

	while (i < size)
	{
		int increase = rand() % 5;
        element = element + increase;


		if(i == 0){
          arr1[i] = element;
		  arr2[i] = element;
		  arr3[i] = element;
		  arr4[i] = element;
          i++;
		}

        if(element > arr1[i-1] && i > 0)
        {
          arr1[i] = element;
		  arr2[i] = element;
		  arr3[i] = element;
		  arr4[i] = element;
          i++;
        }
	}
}

void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
   srand((int)time(NULL)); // random assign

	arr1 = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	arr4 = new int[size];
	int i = 0;

	int base = rand() * 1000;
    int	element = base;


	while (i < size)
	{
		int increase = rand() % 3;
        element = element -increase;


		if(i == 0){
          arr1[i] = element;
		  arr2[i] = element;
		  arr3[i] = element;
		  arr4[i] = element;
          i++;
		}

        if(element < arr1[i-1] && i > 0)
        {
          arr1[i] = element;
		  arr2[i] = element;
		  arr3[i] = element;
		  arr4[i] = element;
          i++;
        }
	}
}

void performanceAnalysis()
{
    int* arr1;
	int* arr2;
	int* arr3;
	int* arr4;
	srand(time(0));
	clock_t startTime = clock();
	double duration;

	int sizeOfArrays[7] = { 6000,10000,14000,18000,22000,26000,30000 };


	string random1[7];
	string random2[7];
	string random3[7];
	string random4[7];
	string asc1[7];
	string asc2[7];
	string asc3[7];
	string asc4[7];
	string des1[7];
	string des2[7];
	string des3[7];
	string des4[7];

	int compCount = 0;
	int moveCount = 0;


	for (int i = 0; i < 7; i++)
	{

		createRandomArrays(arr1, arr2, arr3, arr4, sizeOfArrays[i]);
		compCount = 0;
		moveCount = 0;

		startTime = clock();

		selectionSort(arr1, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * (clock() - startTime) / CLOCKS_PER_SEC;

		random1[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		mergeSort(arr2, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		random2[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		quickSort(arr3, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		random3[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		radixSort(arr4, sizeOfArrays[i]);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		random4[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration);

	}

	for (int i = 0; i < 7; i++)
	{

		createAscendingArrays(arr1, arr2, arr3, arr4, sizeOfArrays[i]);
        cout<<"done"<<endl;
		compCount = 0;
		moveCount = 0;

		startTime = clock();

		selectionSort(arr1, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		asc1[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		mergeSort(arr2, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		asc2[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		quickSort(arr3, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		asc3[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		radixSort(arr4, sizeOfArrays[i]);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		asc4[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration);

	}

	for (int i = 0; i < 7; i++)
	{

		createDescendingArrays(arr1, arr2, arr3, arr4, sizeOfArrays[i]);
        cout<<"doness"<<endl;
		compCount = 0;
		moveCount = 0;

		startTime = clock();

		selectionSort(arr1, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		des1[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		mergeSort(arr2, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		des2[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		quickSort(arr3, sizeOfArrays[i], compCount, moveCount);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		des3[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration) + "\t\t\t" + to_string(compCount) + "\t\t" + to_string(moveCount);

		compCount = 0;
		moveCount = 0;

		startTime = clock();

		radixSort(arr4, sizeOfArrays[i]);

		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

		des4[i] = to_string(sizeOfArrays[i]) + "\t\t\t" + to_string(duration);

	}

	cout << "-----------------------------------------------------\n" << "Analysis of Selection Sort Using Random Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << random1[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Merge Sort Using Random Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << random2[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Quick Sort Using Random Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << random3[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Radix Sort Using Random Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << random4[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Selection Sort Using Ascending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << asc1[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Merge Sort Using Ascending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << asc2[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Quick Sort Using Ascending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << asc3[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Radix Sort Using Ascending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << asc4[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Selection Sort Using Descending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << des1[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Merge Sort Using Descending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << des2[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Quick Sort Using Descending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << "compCount\t\t" << "moveCount\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << des3[i] << endl;

	cout << "-----------------------------------------------------\n" << "Analysis of Radix Sort Using Descending Arrays\n" << "Array Size\t\t" << "Elapsed Time\t\t\t" << endl;

	for (int i = 0; i < 7; i++)
		cout << des4[i] << endl;

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

}
