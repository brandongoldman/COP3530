/* 
	Assignment 4 - Problem 3
	Brandon Goldman
	COP3530 - Spring 2016
*/

#include <iostream>
#include <queue>
#include <vector>
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

Node* createNode(vector<string> &p, vector<string> &i)
{
	// no nodes in postorder
	if(p.empty())
	{
		return NULL;
	}

	// no nodes in inorder
	if(i.empty())
	{
		return NULL;
	}

	// size of postorder doesn't match inorder	
	if(p.size() != i.size())
	{
		return NULL;
	}

	int pSize = p.size() - 1;
	int iSize = i.size() - 1;

	return createTree(p, 0, pSize, i, 0, iSize);
}

Node* createTree(vector<string> &p, int pStart, int pEnd, vector<string> &i, int iStart, int iEnd)
{
	int valueAt = iStart;

	if(start > end)
	{
		return NULL;
	}

	
}

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

int main()
{
    int size;
    cin >> size;

    vector<string> postorder;
    vector<string> inorder;

    string po;
    for(int i = 0; i < size; i++)
    {
    	cin >> po;
    	postorder.push_back(po);
    }

    string in;
    for(int i = 0; i < size; i++)
    {
    	cin >> in;
    	inorder.push_back(in);
    }

    return 0;
}
