#include <iostream>
#include <map>
#include <vector>

using namespace std;

// create map and global variables
const int MAX_NUM_NODES = 10000;
const int MIN_HEIGHT = 1;
int arr[MAX_NUM_NODES + 1];
bool checkIfTree;
map<int, vector<int>> treeContruct;

// check if input is tree
void dfsTree(int node, int index)
{
    arr[node] = MIN_HEIGHT;

    // for each node value in map
    for(int node_val:treeContruct[node])
    {
        if(!arr[node_val])
        {
            dfsTree(node_val, node);
        }
        
        // check if cycle
        else if(arr[node_val] && node_val != index)
            checkIfTree = false;
    }
}

int main() 
{
    int num_nodes;
    int num_edges;
    cin >> num_nodes >> num_edges;

    int node1;
    int node2;
    for(int i = 0; i < num_edges; i++)
    {
        cin >> node1 >> node2;
        // send node values to map
        treeContruct[node1].push_back(node2);
        treeContruct[node2].push_back(node1);
    }

    checkIfTree = true;
    dfsTree(MIN_HEIGHT, MIN_HEIGHT - 1);

    for(int j = 1; j <= num_nodes; j++) 
    {
        if(!arr[j]) 
        {
            checkIfTree = false;
        }
    }

    if(!checkIfTree)
    {
        cout << "NO" << endl;
    }

    else
        cout << "YES" << endl;
    
    return 0;
}
