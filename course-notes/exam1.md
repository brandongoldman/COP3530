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
* [Arrays](#arrays)
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

*Shoutout to [@nickbryanmiller](https://github.com/nickbryanmiller/DataStructuresAndAlgorithms/blob/master/Sorting%20Algorithms/SortingAlgorithms.cpp) for compiling some of the code used below!*
	
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

#### Pointers
* Chain = linked list in which each node represents one element
  * Elements are chained together using links (pointers)
  * Last node has a NULL pointer
  * Example: Get the Second Element: ``` checkIndex(2); desiredNode = firstNode->next->next; return desiredNode->element; ```
  * Deletions can be made with ```delete deletedNode;```
  * How to Insert a New Node at Index 'n':
  
    ```
    // step 1: find node with index 'n-1'
    // step 2: create a new node and set data and link fields
    chainNode<char> *newNode = new chainNode<char>('f', beforeNode->next);
    // step 3: link beforeNode to newNode
    beforeNode->next = newNode;
    ```

* Memory Management (using Linked Systems / C++ Simulated Pointers)
  * Garbage Collection

    ```
    Step 1: Mark nodes that are in use (set mark bits to true)
    Step 2: Compact free space (optional; move all marked nodes to one end of memory and update all pointers)
    Step 3: Move free nodes to storage pool (scan memory for unmarked nodes, else put free block into pool)
    Alternative: ``` delete nameOfMethod; ``` (time to free nodes is proportional to number of nodes being freed rather than total memory size)
    ```

    * Advantages: 
      * Don't need to worry about freeing nodes as they become free
      * Applications run faster with more memory accessible
    * Disadvantages: 
      * Garbage collection time is linear in memory size (not in amount of free memory)
 
* Simulated Pointers = allocate chain of nodes without having to relink / can free chain of nodes in O(1) time when first/last nodes are known


#### Doubly Linked Lists
* Additions to front and end become O(1)
* Can be used to reduce worst-case run time of linear list add/remove/get (by nearly 50%)
  * When searching for index, if index > listSize/2, then start at right hand side (end) of list and search leftwards

---

## Arrays
* 1-D Arrays --> ``` a[0] a[1] a[2] ... a[n] ```
  * Maps into contiguous memory locations
  * Space Overhead = 4 bytes
* 2-D Arrays --> ``` a[0][0] a[0][1] ... a[0][n]; a[1][0] a[1][1] ... a[1][n]; ```
  * Space Overhead = 4 * [# of rows + 1] bytes
* Row-Major Mapping
  * How to Convert 2D --> 1D: ``` x[i][j] in 2-D Array == ic + j in 1-D Array ```
  * Disadvantage = need contiguous memory of size r*c (row * col)
* Column-Major Mapping
  * How to Convert 2D --> 1D:
    * Column elements are collected from top to bottom (columns are collected left to right)
    * Given Matrix: [a,b,c,d; e,f,g,h; i,j,k,l] we convert to get --> y = {a,e,i,b,f,c,g,k,d,h,l}

#### Sparse Matrices
* Sparse Matrices = many elements are zero (single linear list in row-major order)
  * Each nonzero element is represented by ``` list = [row; column; value] ```
  * Node Structure: ``` [row, col; value, next] ```


---

## Stacks
* Properties of Stack:
  * Linear List
  * Two Ends: top & bottom
  * Additions and Removals occur from top of stack only
* Time Complexity:

  ```
  empty() = O(1)
  size() = O(1)
  top() = O(1)
  push() = O(1)
  pop() = O(1)
  ```

---

## Queues
* Properties of Queue:
  * Linear List
  * Two Ends: front & rear
  * Additions are done at rear
  * Removals are done at front
* Time Complexity:

  ```
  empty() = O(1)
  size() = O(1)
  front() = O(1)
  back() = O(1)
  push() = O(size) or O(1) if in array representation
  pop() = O(1)
  ```

* Limitations of a Queue:
  * When the addition of an element will cause the queue to be full, increase the array size
    * Define a boolean variable lastOperationIsPush
      * Following each push, set lastOperationIsPush to true
      * Following each pop, set lastOperationIsPush to false
        * Queue is EMPTY iff: ``` (front == rear) && !lastOperationIsPush ```
        * Queue is FULL iff: ``` (front == rear) && lastOperationIsPush ```
    * Define an integer variable size
      * Following each push, do size++
      * Following each pop, do size--
        * Queue is EMPTY iff: ``` (size == 0) ```
        * Queue is FULL iff: ``` (size == arrayLength) ```
        
---

## Hash Maps
#### Dictionaries
* Collections of Pairs: (key,element) --> pairs have different keys
* Operations
  * find(theKey)
  * erase(theKey)
  * insert(theKey, theElement)
* Time Complexity (Array Representation)
  * find(theKey) = O(size)
  * insert(theKey, theElement) = O(size)
  * erase(theKey) = O(size)
* Time Complexity (Sorted Array)
  * find(theKey) = O(log size)
  * insert(theKey, theElement) = O(log size)
  * erase(theKey) = O(size)
* Time Complexity (Unsorted Chain)
  * find(theKey) = O(size)
  * insert(theKey, theElement) = O(size) to verify duplicate, O(1) to add at left end
  * erase(theKey) = O(size)
* Time Complexity (Sorted Chain)
  * find(theKey) = O(size)
  * insert(theKey, theElement) = O(size) to verify duplicate, O(1) to put at proper place
  * erase(theKey) = O(size)

#### Hash Tables
* Worst-case time complexity for find, insert, and erase is O(size) --> best-case is O(1)
* Ideal Hashing has a bucket at every position of the array (each bucket holds one dictionary pair)
* Functions get, put, and remove take O(1) time
* How To Map Into Home Bucket: ``` homeBucket = hash(theKey) % (numberOfBuckets) ```
* The number of ints that get mapped (hashed) to bucket i is: ``` (2^32)/b ``` where b is a prime & odd integer
* How To Handle Overflow
  * Search hash table for empty bucket
  * Eliminate overflows by permitting each bucket to keep a list of all pairs for which it is a home bucket
* Hash Table Design
  * Dynamic Resizing (whenever loading density > threshold, rehash into table that is twice current size)
  * Fixed Size (when you have a known maximum number of pairs)

---

## Compression
* Goal: reduce size of data (reduce storage space --> reduce storage cost) and reduce time needed to retrieve/transmit data
* Compression Ratio = ``` (Original Data Size) / (Compressed Data Size) ```
* Lossless vs. Lossy
  * Lossless = data is not changed (originalData == decompressedData)
    * Used in text file compression (where data changes are not acceptable)
    * Examples: zip and compress (based on LZW)
  * Lossy = data is changed (originalData != decompressedData)
    * Obtains higher compression ratios
    * Used in image/video applications (where data changed are unnoticable)
* LZW Compression
  * Character sequences in original text are replaced by codes that are dynamically determined
  * Code table is not encoded into the compressed text (it may not be reconstructed from compressed text during decompression)
* Time Complexity: ('n' is the length of the text file)
  * Compression = O(n)
  * Decompression = O(n)
  * Complexity is determined based on the fact that the complexity of computing the home bucket in a hash table is O(1)

---

## Trees
* Trees are useful for hierarchically ordered data
* Elements of a Tree:
    ```
    				  [Root]			// Root = element at top of hierarchy (tree)
    				  /
    	           [Child]				// Children = elements next in hierarchy (under root)
    		       /      \
    	 [Grandchild]    [Grandchild]   // Grandchildren = elements next in hierarchy
           /      \		   /      \
    	[Leaf]  [Leaf]  [Leaf]  [Leaf]  // Leaves = elements without children
    ```

* Height of Tree = h = # of Levels
* Node Degree = # of Children
* Tree Degree = max(Node Degree)

#### Binary Trees
* Node may not have degree > 2, but can be empty
* Subtrees are ordered (greater value will either always be on left or always be on right)
* Minimum Number of Nodes = ``` height = h ```
* Maximum Number of Nodes = ``` 2^h - 1 ```
* Right-Skewed Binary Tree
  * Transforms into array whose length is between ```n+1``` and ```2^n```
* Operations:
  * find(i) = return the element that is in the root (ex: ```find(leaf)``` returns ```grandchild```)
    * Time Complexity = O(log n) or (at worst) O(n)
  * union(i,j) = unite two trees by making one a subtree of the other (i and j are roots of separate trees)
    * Time Complexity = O(1)
* Height Rule:
  * Make tree with smaller height a subtree of the other
  * Height increases only when two trees of equal height are united
* Weight Rule:
  * Make tree with fewer elements a subtree of the other
  * Weight of new tree is sum of weights of the two trees that were united

#### Traversal Methods
* Preorder (VLR)
  * Visit --> Left --> Right
  ```
   		   (a)		// first: visit a
  		   / \		// second: go left to b
  		(b)  (c)	// third: go right to c
  	Output: abc
  ```

* Inorder (LVR)
  * Left --> Visit --> Right
  ```
   		   (a)		// first: go left to b
  		   / \		// second: visit a
  		(b)  (c)	// third: go right to c
  	Output: bac
  ```

  * Shortcut: Projection! (output is derived from going left to right and printing)

* Postorder (LRV)
  * Left --> Right --> Visit
  ```
   		   (a)		// first: go left to b
  		   / \		// second: go right to c
  		(b)  (c)	// third: visit a
  	Output: bca
  ```

* Level Order (Zig Zag)
  * Left --> Right --> Down --> Left --> Right ...
  ```
   		   (a)		// first: visit a
  		   / \		// second: go down to first element on next level (b)
  		(b)  (c)	// third: go right (c) and repeat
  	Output: abc
  ```

* Traversal Applications
  * Make a Clone (use Postorder Traversal to clone left, right, and visit)
  * Determine Height (```Height = 1 + Max(heightLeft, heightRight)```)
  * Determine Number of Nodes (use any method desired and increment a counter)
