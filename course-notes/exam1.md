# COP3530 - Exam 1 Notes
#### Spring 2016 | Compiled by: Brandon Goldman

These notes were compiled using material found online as well as in the presentations provided by Professor Alipour.

## Table of Contents

* [Sorting Algorithms](#sorting-algorithms)
  * [Insertion Sort](#insertion-sort)
  * [Bubble Sort](#bubble-sort)
  * [Selection Sort](#selection-sort)
  * [Heap Sort](#heap-sort)
  * [Merge Sort](#merge-sort)
  * [Quick Sort](#quick-sort)
* [LinearList](#linearlist)
* [LinkedList](#linkedlist)
* [Stacks](#stacks)
* [Queues](#queues)
* [Hash Maps](#hash-maps)
* [Compression](#compression)
* [Trees](#trees)

---

## Sorting Algorithms

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
* Time Complexity = O(n^2)
  * Best-Case = O(n)
  * Worst-Case = O(n^2)
* Adaptive? *Yes*

### Bubble Sort
```
void BubbleSort(int array[], int size) {
    bool sorted = false;
    for (int i = 0; (i < size - 1) && sorted == false; i++) {
        sorted = true;
        for (int j = 0; j < size - 1; j++) {
            if (array[j+1] < array[j]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                
                sorted = false;
            }
        }
    }
}
```
* Space Complexity = O(1)
* Time Complexity = O(n^2)
  * Best-Case = O(n)
  * Worst-Case = O(n^2)
* Adaptive? *Yes*

### Selection Sort
```
void selectionSort(int array[], int size) {
    int minPos;
    int temp;
    for (int i = 0; i < size - 1; i++) {
        //	set minPosition to the current index of array
        minPos = i;
        
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minPos]) {
                //	minPosition will keep track of the index that min is in
                minPos = j;
            }
        }
        //	Swap the value of i with the new minPosition
        if (minPos != i) {
            temp = array[i];
            array[i] = array[minPos];
            array[minPos] = temp;
        }
    }
}
```
* Space Complexity = O(1)
* Time Complexity = O(n^2)
  * Best-Case = O(n^2)
  * Worst-Case = O(n^2)
* Adaptive? *No*

### Heap Sort
```
void maxHeap(int a[], int i, int n) {
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if((r<=n)&&(a[r]>a[largest]))
        largest=r;
    if(largest!=i)
    {
        loc=a[i];
        a[i]=a[largest];
        a[largest]=loc;
        maxHeap(a, largest,n);
    }
}
void buildMaxHeap(int a[], int n) {
    for(int k = n/2; k >= 1; k--)
    {
        maxHeap(a, k, n);
    }
}
void heapSort(int a[], int n) {
    
    buildMaxHeap(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        maxHeap(a, 1, i - 1);
    }
}
```
* Space Complexity = O(1)
* Time Complexity = O(n*log(n))
  * Best-Case = O(n*log(n))
  * Worst-Case = O(n*log(n))
* Adaptive? *No*

### Merge Sort
```
/* leftIndex is for left index and rightIndex is right index of the sub-array of array to be sorted */
void merge(int array[], int leftIndex, int middleIndex, int rightIndex) {
    int i, int j, int k;
    int n1 = middleIndex - leftIndex + 1;
    int n2 =  rightIndex - middleIndex;
    
    /* create two temp arrays */
    int leftTempArray[n1], int rightTempArray[n2];
    /* Copy data to temp arrays leftTempArray[] and righTempArray[] */
    for(i = 0; i < n1; i++) {
        leftTempArray[i] = array[leftIndex + i];
    }
    for(j = 0; j < n2; j++) {
        rightTempArray[j] = array[middleIndex + 1+ j];
    }
    /* Merge the temp arrays back into array[leftTempArray..rightTempArray]*/
    i = 0, j = 0, k = leftIndex;
    while (i < n1 && j < n2) {
        if (leftTempArray[i] <= rightTempArray[j]) {
            array[k] = leftTempArray[i];
            i++;
        }
        else {
            array[k] = rightTempArray[j];
            j++;
        }
        
        k++;
    }
    /* Copy the remaining elements of leftTempArray[], if there are any */
    while (i < n1) {
        array[k] = leftTempArray[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of rightTempArray[], if there are any */
    while (j < n2) {
        array[k] = rightTempArray[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        //Same as (leftIndex + rightIndex)/2, but avoids overflow for large leftIndex and h
        int middleIndex = leftIndex + (rightIndex - leftIndex) /2;
        mergeSort(array, leftIndex, middleIndex);
        mergeSort(array, middleIndex + 1, rightIndex);
        merge(array, leftIndex, middleIndex, rightIndex);
    }
}
```
* Space Complexity = O(n) for Array, O(log(n)) for Linked List
* Time Complexity = O(n*log(n))
  * Best-Case = O(n*log(n))
  * Worst-Case = O(n*log(n))
* Adaptive? *No*

### Quick Sort
```
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
```
* Space Complexity = O(1)
* Time Complexity = O(n*log(n))
  * Best-Case = O(n*log(n))
  * Worst-Case = O(n*log(n))
* Adaptive? *No*

---

## LinearList
* Operators:
  * size() = determines list size
  * get(theIndex) = get element with given index
  * indexOf(theElement) = determine the index of an element (returns -1 if element not present)
  * erase(theIndex) = remove/delete element with given index (returns 'error' if index not present)
  * insert(theIndex, theElement) = add an element so that the new element has specified index
  * output() = output list of elements from left to right

* How to Extend a C++ Class:
  
  ```
  template<class T>
    class arrayList : public linearList<T> 
	{
	   // code for all abstract methods of linearList must come here
	}
  ```

* Arrays as Linear Lists
  * Increase size of array? Create new (larger) array [at least 1 index larger than old] --> copy elements --> delete old (smaller) array
    * Cost of Increasing Size: Theta(size of old array)
    * Cost of Inserting Into Empty Array: Theta(n^2)
    * Space Complexity of New Array: [Space Needed] = 2 * [newLength] - 1 = 2 * [maxListSize] - 1
  * Array Doubling
    * Time needed for 'n' inserts increases by Theta(n)
    * Space Complexity of New Array: [Space Needed] = 1.5 * [newLength] <= 3 * [maxListSize] - 3
  * How big should the new array be?
    * Resize by Constant Factor: [newLength] = c * [oldLength]
    * Increases cost of 'n' inserts by Theta(n)
    * Increases cost of 'n' add operations by Theta(n^2)
    * Resizing by additive constant 'c' requires space that is at most: 2 * [maxListSize - 1] + c 
    
---

## LinkedList
* Iterators permit you to examine the elements of a data structure one at a time (ex: input, output, forward, bidirectional, reverse iterators)
  * Bidirectional Iterators = allow both forward and backward movement through the elements of a data structure 
  * Syntax: ``` iterator(T *thePosition) ``` 
    * Constructs iterator positioned at specified element
    * Dereferenced using * and ->
    * Incrementation using ++ and --
    * Equality Testing using == and !=
  * begin() = returns iterator positioned at element 0 of list
  * end() = returns iterator positioned one past last element


---

## Stacks

---

## Queues

---

## Hash Maps

---

## Compression

---

## Trees

