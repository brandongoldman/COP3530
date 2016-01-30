/* 
	Algorithm: Linked Lists
	Problem: Interleave multiple lists
	Brandon Goldman
	COP3530 - Spring 2016
	
*/

#include <iostream>
using namespace std;

// The following code is the template for a LinkedList.
// Code derived from my previous programming course class projects

/* The Node class is responsible for the components of the
 * Linked List. Each node will hold the data value, in this
 * case an integer, and we will create a node for each of 
 * the N elements in a given Linked List. 
 * */
class Node
{
	public:
		int value;
		Node* nextNode;
		
		Node(int number)
		{
			value = number;
		}
		
		Node(int ptrNum, Node* nodeNum)
		{
			value = ptrNum;
			nextNode = nodeNum;
		}
	
};

/* The Linked List class will handle each node. Each method
 * within the Linked List class is individually commented.
 * */
class LinkedList
{
	public:
		Node* head;
		int size;

		// create our list
		LinkedList() 
		{
			head = NULL; 	// initial head points to NULL
			size = 0;		// list size initially has zero elements
		}
			
		// each list contains n elements, declared by counter variable
		int listSize()
		{
			Node* temp = head;			// declare location of node head (start)
			int counter = 0;			// counter keeps track of number of elements being added
				
			while(temp != NULL)
			{
				counter++; 				// increase size by one element
				temp = temp->nextNode;	// point to next element
			}
			
			return counter;
		}
		
		// set head pointer = head node
		Node* getHead(int index)
		{
			Node* temp = head;
			
			while(index > 0)
			{
				index--;
				if(temp != NULL)
				{
					temp = temp->nextNode;	// point to following node
				}
				else return NULL;
			}
			return temp;
		}
			
		void insert(int val)
		{
			// if the next element is NULL, then we need to create new Node and insert value
			if(head == NULL)
			{
				head = new Node(val);
			}
			
			// otherwise point to next Node and insert value
			else
			{
				Node* temp = head;
					
				while(temp->nextNode != NULL)	// is this right syntax??
				{
					temp = temp->nextNode;
				}

				temp->nextNode = new Node(val);
			}
			size++;								// update number of nodes
		}
			
			// this method retrieves the values at a given position
			int getValue(int position)
			{
				Node* temp = getHead(position);
				return temp->value;
			}
			
			void interleave(int value, int position)
			{
				Node* tail = getHead(position - 1); 		// get the pointer of previous node
				
				if(position == 0)							// create new node if first
				{
					head = new Node(value);
				}

				else
					tail->nextNode = new Node(value, tail->nextNode);
				
				size++;
			}
			
			// redirect pointers based on given step size
			void stepSize(LinkedList createNew, int step)
			{
				for(int i = 0; i < createNew.listSize(); ++i)
				{
					// length of first list is bigger than length of second list * step
					this->interleave(createNew.getValue(i), (step + 1)*i + step);
				}
			}
			
			// simple method to print list node by node
			// code adopted from course presentation slide
			void print()
			{
				Node *temp = head;
				
				while(temp != NULL)
				{
					cout << temp->value << " ";
					temp = temp->nextNode;
				}
			}
};

/* The Linked List class will handle each node. Each method
 * within the Linked List class is individually commented.
 * */
int main()
{
	// declare initial list
    LinkedList list;

	// declare number of elements (N) in initial list
    int inputSize;
    cin >> inputSize;

	// take in N numbers
    for(int i = 0; i < inputSize; i++)
    {
    	int temp;
    	cin >> temp;
    	list.insert(temp);
    }
	
	// additional lists? if yes, create one
    int additionalList;
    cin >> additionalList;

    for(int i = 0; i < additionalList; i++)
    {
    	int stepSize;								// enter step size of new list
		cin >> stepSize; 							// >> numElementsAdditional;
		
		int numElementsAdditional;					// enter number of elements in list
		cin >> numElementsAdditional;

		// if there is an additional list, create a new Linked List
    	LinkedList additionalList;
		
    	for(int j = 0; j < numElementsAdditional; j++)
    	{
    		int tempNode;
    		cin >> tempNode;
    		additionalList.insert(tempNode);
    	}
		
		// add new list and new step size to existing list
    	list.stepSize(additionalList, stepSize);
    }

    list.print();	// print the Linked List
	cout << "\n";	// break line for multiple test cases *not necessary*
	
    return 0;
}
