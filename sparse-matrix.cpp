/* 
	Algorithm: Sparse Matrices
	Brandon Goldman
	COP3530 - Spring 2016
*/

#include <iostream>
#include <cstdio>
using namespace std;

/*********************
***** LinkedList *****
*********************/

struct LinkedList
{
    int values; 
    int col;
    LinkedList *ptr;
    
    LinkedList(int col, int values)
    {
        this->col = col;
        this->values = values;
    }
};

/****************
***** Nodes *****
****************/

// list of Nodes for Matrix 1
LinkedList *head;
LinkedList *currentNode;
LinkedList *temp_next_element;

// list of Nodes for Matrix 2
LinkedList *head2;
LinkedList *currentNode_M2;
LinkedList *temp_next_element_M2;

void createNode(int colNum, int colVal)
{
    LinkedList *node = new LinkedList(colNum, colVal);
    node->ptr = NULL;
    node->col = colNum;
    node->values = colVal;
    
    if(head != NULL)
    {
        currentNode = head;
        while(currentNode->ptr != NULL)
        {
            currentNode = currentNode->ptr;
        }
        currentNode->ptr = node;
    }
    else
    {
        head = node;
    }
}

/***********************************
***** Addition of Two Matrices *****
***********************************/

void Addition()
{
	int dummy_Col, dummy_value;			// these will help us create temporary indexes
	int index_M1 = 0, index_M2 = 0;		// start with initial index -> value = 0
	
	// keep track of node head for matrix 1 and 2
	currentNode = head;
	currentNode_M2 = head2;
	
	// statement runs when the next element exists in matrix 1
    if(head->ptr != NULL)
    {
        currentNode = head->ptr;
        ++index_M1;	// go to next index
		
        while(currentNode->ptr != NULL)
        {
        	currentNode = currentNode->ptr;
        	++index_M1;	// go to next index
        }
        currentNode = head->ptr;
    }
	
	// statement runs when the next element exists in matrix 2
    if(head2->ptr != NULL)
    {
        currentNode_M2 = head2->ptr;
        ++index_M2;
		
        while(currentNode_M2->ptr != NULL)
        {
        	currentNode_M2 = currentNode_M2->ptr;
        	++index_M2;
        }
		
        currentNode_M2 = head2->ptr;
    }
	
    // check if node is null
    while(index_M1 > 0 || index_M2 > 0)
    {
        if((currentNode_M2->col < currentNode->col) && index_M2 > 0)
        {
            temp_next_element = currentNode->ptr;
            temp_next_element_M2 = currentNode_M2;
            
			if(currentNode_M2->ptr != NULL)
            {
            	currentNode_M2 = currentNode_M2->ptr;
            }
			
            else
            {
                currentNode_M2 = head2;
            }
			
            currentNode->ptr = temp_next_element_M2;
            temp_next_element_M2->ptr = temp_next_element;
			
            dummy_Col = temp_next_element_M2->col;
            dummy_value = temp_next_element_M2->values;
			
            temp_next_element_M2->col = currentNode->col;
            currentNode->col = dummy_Col;
			
            temp_next_element_M2->values = currentNode->values;
            currentNode->values = dummy_value;
			
            currentNode = currentNode->ptr;
            --index_M2;
        }
		
        else if((currentNode_M2->col < currentNode->col) && index_M2 == 0)
        {
            index_M1 = 0;
        }
		
        else if((currentNode->col < currentNode_M2->col) && index_M1 > 0)
        {
        	if(currentNode->ptr != NULL)
        	{
                currentNode = currentNode->ptr;
            }
            --index_M1;
        }
		
        else if((currentNode->col < currentNode_M2->col) && index_M1 == 0)
        {
        	while(currentNode_M2 != NULL)
        	{
			temp_next_element = currentNode->ptr;
			temp_next_element_M2 = currentNode_M2;
				
			currentNode_M2 = currentNode_M2->ptr;		// ptr points to next element
			currentNode->ptr = temp_next_element_M2;
				
			temp_next_element_M2->ptr = temp_next_element;
			--index_M2;
        	}
        }
		
        else if((currentNode->col == currentNode_M2->col) && index_M1 > 0 && index_M2 > 0)
        {
            currentNode->values = currentNode->values + currentNode_M2->values;
            if(currentNode->ptr != NULL)
        	{
                currentNode = currentNode->ptr;
            }
            if(currentNode_M2->ptr != NULL)
            {
            	currentNode_M2 = currentNode_M2->ptr;
            }
            --index_M1;
            --index_M2;
        }
    }
} 

/**************************
***** Search Function *****
**************************/

void MatrixSearch(int val, int row)
{
    currentNode = head;
	
    while(currentNode->ptr != NULL)
    {
        if(currentNode->ptr->values == val)
        {
            cout << row << " " << currentNode->ptr->col << " ";	// print "row col"
        }
        currentNode = currentNode->ptr; // update pointer
    }
}

/*************************
***** Display Output *****
*************************/

void print(int numCols)
{
    if(head->ptr == NULL)
    {
        for(int i = 0; i <= numCols; ++i)
        {
            cout << "0 ";
        }
        cout << endl;
    }
    else
    {
        currentNode = head->ptr;
        for(int i = 0; i <= numCols; ++i)
        {
            if(currentNode->col == i)
            {
                cout << currentNode-> values << " ";
                if(currentNode->ptr != NULL)
                {
                    currentNode = currentNode->ptr;
                }
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

/***********************
***** Clear Memory *****
***********************/

void Deallocate()
{
    temp_next_element = head;
    currentNode = head;
    while(currentNode != NULL)
    {
        temp_next_element = currentNode;
        currentNode = currentNode->ptr;
        delete temp_next_element;
    }
}

/****** MAIN METHOD ******/
int main()
{
	ios::sync_with_stdio(false); // time efficiency statement
	
    int numRows, elements_per_row, col, value, maxRowLength;
	
	// initially there are zero elements in each row (assume entities are zero)
    int lengthM1 = 0; 
	int lengthM2 = 0;
	
	// default search for zero elements
    int numElementsToSearch = 0;
   
/*******************
***** MATRIX 1 *****
*******************/

    cin >> numRows;
	
	// create array of pointers containing numRows pointers
    LinkedList **matrix1 = new LinkedList*[numRows];
	
	// create head node at beginning of each array index
    for(int i = 0; i < numRows; i++)
    {
        matrix1[i] = new LinkedList(-1, 0);
    }

    for (int i = 0; i < numRows; i++)
    {
        head = matrix1[i];
        cin >> elements_per_row;
		
        for (int j = 0; j < elements_per_row; j++)
        {
            cin >> col;
            cin >> value;
			
			// send col, value to list
            createNode(col, value);
			
			// update matrix col size if input col > length
            if(col > lengthM1)
            {
                lengthM1 = col;
            }
        }
    }
    
/*******************
***** MATRIX 2 *****
*******************/

    cin >> numRows;
    LinkedList **matrix2 = new LinkedList*[numRows];
   
   for(int i = 0; i < numRows; i++)
    {
        matrix2[i] = new LinkedList(-1, 0);
    }

    for (int i = 0; i < numRows; i++)
    {
        head = matrix2[i];
        cin >> elements_per_row;
		
        for (int j = 0; j < elements_per_row; j++)
        {
            cin >> col;
            cin >> value;
			
            createNode(col, value);
			
            if(col > lengthM2)
            {
                lengthM2 = col;
            }
        }
    }

/***********************************
***** Update Number of Columns *****
***********************************/	
	    
    if(lengthM1 > lengthM2)
    {
        maxRowLength = lengthM1;
    }
    else
    {
        maxRowLength = lengthM2;
    }
    
    for(int i = 0; i < numRows; i++)
    {
            head = matrix1[i];
            head2 = matrix2[i];
            Addition();
    }
	
/*****************
***** Search *****
*****************/	
    
	// number of values to search for
    cin >> numElementsToSearch;
    int *searchFor = new int[numElementsToSearch];
	
	// values to search for (line by line)
    for(int i = 0; i < numElementsToSearch; i++)
    {
        cin >> searchFor[i];
    }
    
    for(int i = 0; i < numElementsToSearch; i++)
    {
        for(int j = 0; j < numRows; j++)
        {
            head = matrix1[j];
            MatrixSearch(searchFor[i], j);
        }
        cout << endl;
    }    

/*****************************
***** Garbage Collection *****
*****************************/	
	
	// free up memory from matrix 1
    for(int i = 0; i < numRows; i++)
    {
        head = matrix1[i];
        Deallocate();
    }
	
	// free up memory from matrix 2
    for(int i = 0; i < numRows; i++)
    {
        head = matrix2[i];
        Deallocate();
    }
    
    return 0;
}
