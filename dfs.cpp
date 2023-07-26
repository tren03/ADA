#include <iostream>
#include <vector>

using namespace std;

// Function to perform Depth-First Search (DFS) recursively
void dfsRecursive(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " "; // Process the current node

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, graph, visited);
        }
    }
}

// Function to initialize the DFS traversal for the whole graph
void dfs(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();//number of nodes
    vector<bool> visited(numNodes, false);

    dfsRecursive(startNode, graph, visited);
}

int main() {
    // Example graph represented using an adjacency list
    vector<vector<int>> graph = {
        {},           // Node 0: No neighbors
        {2, 3, 4},    // Node 1: Neighbors 2, 3, 4
        {1, 5, 6},    // Node 2: Neighbors 1, 5, 6
        {1, 7},       // Node 3: Neighbors 1, 7
        {1},          // Node 4: Neighbor 1
        {2},          // Node 5: Neighbor 2
        {2},          // Node 6: Neighbor 2
        {3}           // Node 7: Neighbor 3
    };

    int startNode = 1; // Starting node for the DFS traversal

    cout << "DFS traversal starting from node " << startNode << ": ";
    dfs(graph, startNode);

    return 0;
}
