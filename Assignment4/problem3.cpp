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

void createTree(vector<string> &p, vector<string> &i)
{
	if(p.empty())
	{
		return NULL;
	}

	if(i.empty())
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

void 

    static TreeNode* createTreeFromPreOrder(int inorder[],int preorder[], int start, int end)
    {
        static int position = 0;
        if(start>end)
        {
            return NULL;
        }
        TreeNode* temp = new TreeNode();
        temp->value = preorder[position++];
        if(start==end)
        {
            return temp;
        }
        int mid = search(inorder,start,end,temp->value);
        temp->left = createTreeFromPreOrder(inorder,preorder,start, mid-1);
        temp->right = createTreeFromPreOrder(inorder,preorder,mid+1,end);
        return temp;
    }

    static TreeNode* createTreeFromPostOrder(int inorder[],int postorder[], int start, int end)
    {
        static int position = end;
        
        if(start>end)
        {
            return NULL;
        }

        TreeNode* temp = new TreeNode();
        temp->value = postorder[position--];
        
        if(start==end)
        {
            return temp;
        }

        int mid = search(inorder,start,end,temp->value);
        temp->right = createTreeFromPostOrder(inorder,postorder,mid+1,end);
        temp->left = createTreeFromPostOrder(inorder,postorder,start, mid-1);
        return temp;
    }

    static TreeNode* createTreeFromLevelOrder(int inorder[],int levelorder[], int start, int end,int level)
    {
        if(start>end)
        {
            return NULL;
        }

        TreeNode* temp = new TreeNode();
        temp->value = levelorder[level-1];

        if(start==end)
        {
            return temp;
        }

        int mid = search(inorder,start,end,temp->value);
        temp->left = createTreeFromLevelOrder(inorder,levelorder,start, mid-1,2*level);
        temp->right = createTreeFromLevelOrder(inorder,levelorder,mid+1,end,2*level+1);
        return temp;
    }
};

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
