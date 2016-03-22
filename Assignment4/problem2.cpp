/* 
	Assignment 4 - Problem 2
	Brandon Goldman
	COP3530 - Spring 2016
*/

#include<iostream>
#include<string>
#include<queue>
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

void Levelorder(Node *n)
{
	if(n == NULL)
	{
		return;
	}

	queue<Node*> q;

	// push root
	q.push(n);

	while(!q.empty())
	{
		Node *current = q.front();
		q.pop();
		cout << current->data << " ";

		if(current->left != NULL)
		{
			q.push(current->left);
		}

		if(current->right != NULL)
		{
			q.push(current->right);
		}
	}
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

	// levelorder
	Levelorder(n);
	cout << endl;

	return 0;
}
