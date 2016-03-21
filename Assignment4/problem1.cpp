/* 
	Assignment 4 - Problem 1
	Brandon Goldman
	COP3530 - Spring 2016
*/

#include<iostream>
#include<string>
using namespace std;
 
struct Node 
{
	string data;
	Node *left;
	Node *right;

	Node(string s)
	{
		data = s;
		left = NULL;
		right = NULL;
	}
};

void Preorder(Node *n)
{
	if(n == NULL)
	{
		return;
	}

	cout << n->data << " ";
	// printf("%c ", n->data); // Print data
	Preorder(n->left);      // Visit left subtree
	Preorder(n->right);     // Visit right subtree
}

void Inorder(Node *n) 
{
	if(n == NULL) 
	{
		return;
	}

	Inorder(n->left);       // Visit left subtree
	cout << n->data << " ";
	// printf("%c ",n->data);  // Print data
	Inorder(n->right);      // Visit right subtree
}

void Postorder(Node *n) 
{
	if(n == NULL)
	{
		return;
	}

	Postorder(n->left);    // Visit left subtree
	Postorder(n->right);   // Visit right subtree
	
	cout << n->data << " ";

	// printf("%c ",n->data); // Print data
}

void addNode(Node* n, string* s, int* lChild, int* rChild, int x) 
{
	if(lChild[x] != -1) 
	{
		n->left = new Node(s[lChild[x]]);
		addNode(n->left, s, lChild, rChild, lChild[x]);
	}

	if(rChild[x] != -1) 
	{
		n->right = new Node(s[rChild[x]]);
		addNode(n->right, s, lChild, rChild, rChild[x]);
	}
}
 
int main()
{
	// take in number of nodes
	int numberOfNodes;
	cin >> numberOfNodes;

	// store input for nodes
	string nodeString;
	int leftChild;
	int rightChild;
	int initialVal = 0;

	string* nodeVals = new string[numberOfNodes];
	int* lChildVals = new int[numberOfNodes];
	int* rChildVals = new int[numberOfNodes];

	for(int i = 0; i < numberOfNodes; i++)
	{
		cin >> nodeString >> leftChild >> rightChild;

		nodeVals[i] = nodeString;
		lChildVals[i] = leftChild;
		rChildVals[i] = rightChild;
	}

	// create Node for root
	// Node* n = NULL;

	Node* n = new Node(nodeVals[initialVal]);
	addNode(n, nodeVals, lChildVals, rChildVals, initialVal);

	// postorder
	Postorder(n);
	cout << endl;

	// inorder
	Inorder(n);
	cout << endl;

	// preorder
	Preorder(n);
	cout << endl;

	return 0;
}
