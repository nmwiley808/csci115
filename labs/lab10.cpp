#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_NODES = 10;

// Add undirected edge
void addEdge (vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Recursive DFS helper
void dfsUtil (int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited);
        }
    }
}

// DFS starting from node 1
void DFS (int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(MAX_NODES + 1, false); // 1-indexed
    cout << "DFS Traversal: ";
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited);
        }
    }
    cout << endl;
}

// BFS starting from node 1
void BFS (int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(MAX_NODES + 1, false);
    queue<int> q;

    cout << "BFS Traversal: ";

    for (int start = 1; start <= numNodes; ++start) {
        if (!visited[start]) {
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node << " ";

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    cout << endl;
}

int main () {
    int numNodes;
    cout << "Enter number of nodes (1-10): ";
    cin >> numNodes;

    if (numNodes < 1 || numNodes > MAX_NODES) {
        cerr << "Invalid number of nodes" << endl;
        return 1;
    }

    vector<vector<int>> adj(MAX_NODES + 1); // 1-indexed

    int numEdges;
    cout << "Enter number of edges (1-10): ";
    cin >> numEdges;

    cout << "Enter edges (pairs of connected nodes, e.g., 1 2): \n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 1 || u > MAX_NODES || v < 1 || v > MAX_NODES) {
            cerr << "Invalid edge" << endl;
            return 1;
        }
        addEdge(adj, u, v);
    }

    DFS(numNodes, adj);
    BFS(numNodes, adj);

    return 0;
}
