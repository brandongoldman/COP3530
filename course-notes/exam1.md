# COP3530 - Exam 1 Notes
#### Spring 2016 | Compiled by: Brandon Goldman

These notes were compiled using material found online as well as in the presentations provided by Professor Alipour.

## Table of Contents

* [Sorting](#sorting)
* [LinkedList](#linkedlist)

---

## Sorting

* Step Count = amount of computing that does not depend on instance characteristic of n
* Worst-Case Count = maximum count
* Best-Case Count = minimum count
* Space Complexity = how much storage (memory) an algorithm needs
* Time Complexity = how much time an algorithm needs to run a function
  * Big-Oh Notation (*exludes coefficients and lower order terms*)

* Performance Analysis
  * Determines practicality of algorithm & determines run time on large test cases
  * Helps make comparisons between two algorithms (*example:* O(n) vs O(n^2))

* Timing in C++
  ```
  clock_t startTime = clock();
  long numberOfRepititions;
  do
  {
  	numberOfRepititions++;
  	doSomething();
  } while(clock() - startTime < 1000)
  double elapsedMillis = (clock() - startTime) / clocksPerMillis;
  double timeForCode = elapsedMillis / numberOfRepetitions;
  ```

*Shoutout to the coding prodigy [@nickbryanmiller](https://github.com/nickbryanmiller/DataStructuresAndAlgorithms/blob/master/Sorting%20Algorithms/SortingAlgorithms.cpp) for compiling some of the code used below!*
	
### Insertion Sort
```
void InsertionSort(int array[], int size) 
{
    int j;
    for (int i = 0; i <= size - 1; i++) 
    {
        j = i;
        while (j > 0 && array[j] < array[j-1]) {
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
}
```
* Space Complexity = O(1)
* Time Complexity
  * Best-Case = O(n)
  * Worst-Case = O(n^2)
* Asymptotic Complexity of Insertion Sort = O(n^2)

### Bubble Sort
### Selection Sort
### Count Sort
### Shaker Sort
### Shell Sort
### Heap Sort
### Merge Sort
### Quick Sort

---

## LinkedList
