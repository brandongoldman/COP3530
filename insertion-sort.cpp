/* 
	Algorithm: Insertion Sort
	Brandon Goldman
	COP3530 - Spring 2016
*/

#include <iostream>
using namespace std;

void insertionSort(int array[], int size);
void printArray(int array[], int size);

int main()
{
	/* 	1. Enter size of array
		2. Create an array of that size
		3. Input elements in the array
	*/

	// take in size of array
	int size;
	cin >> size;
	
	// declare array
	int array[size];
	
	// fill array with numbers
	for(int i = 0; i < size; ++i){
		cin >> array[i];
	}
	
	// send to insertionSort algorithm
	insertionSort(array, size);
	
	// print results
	printArray(array, size);
	
	return 0;
}


void insertionSort(int array[], int size){
	int temp, j;
	for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > 0; j--) {
            if (array[j] < array[j-1]) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

void printArray(int array[], int size){
	cout << "\n";
	for(int i = 0; i < size; i++){
		cout << array[i] << "\n";
	}
}
