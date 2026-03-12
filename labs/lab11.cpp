#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

// Utility: Print Adjacency Matrix
void printMatrix(const vector<vector<int>>& output) {
    const int v = output.size();
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

// Prim's MST
void primsMST(const vector<vector<int>>& graph, const int start) {
    int V = graph.size();
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    vector<int> parent(V,-1);

    key[start] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int minKey = INF, u = -1;

        for (int v = 0; v < V; ++v)
            if (!inMST[v] && key[v] < minKey)
                minKey = key[v], u = v;

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    vector<vector<int>> mst(V, vector<int>(V, 0));
    for (int i = 1; i < V; ++i) {
        mst[i][parent[i]] = mst[parent[i]][i] = graph[i][parent[i]];
    }

    cout << "\nPrim's MST Adjacency Matrix:\n";
    printMatrix(mst);
}

// Kruskal's MST
int find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] < rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskalMST(const vector<vector<int>>& graph, int start) {
    const int V = graph.size();
    vector<Edge> edges;

    for (int i = 0; i < V; ++i)
        for (int j = i + 1; j < V; ++j)
            if (graph[i][j] != 0)
                edges.push_back(Edge(i, j, graph[i][j]));

    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for(int i = 0; i < V; ++i)
        parent[i] = i;

    vector<vector<int>> mst(V, vector<int>(V,0));
    for (const auto& e : edges) {
        if(find(parent, e.u) != find(parent, e.v)) {
            mst[e.u][e.v] = mst[e.v][e.u] = e.weight;
            unionSets(parent, rank, e.u, e.v);
        }
    }

    cout << "\nKruskal's MST Adjacency Matrix: \n";
    printMatrix(mst);
}

// Main
int main() {
    int V, start;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency Matrix:\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];
    cout << "Enter start node (0-based index): ";
    cin >> start;

    int choice;
    cout << "\nChoose MST Algorithm:\n1. Prim's MST\n.2 Kruskal's MST\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        primsMST(graph, start);
    else if (choice == 2)
        kruskalMST(graph, start);
    else
        cout << "Invalid Input!\n";

    return 0;
}
