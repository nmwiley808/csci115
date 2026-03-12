#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

// Function to find the vertex with the minimum distance
int minDistance(const vector<int>& dist, const vector<bool>& visited, int V) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, visited, V);
        if (u == -1)break;
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output results
    cout << "Vertex\t\tDistance from Source vertex\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF)
            cout << i << "\t\t" << "INF" << '\n';
        else
            cout << i << "\t\t" << dist[i] << '\n';
    }
}

int main() {
    int V, S;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter source vertex: ";
    cin >> S;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (enter 0 if no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    dijkstra(graph, S, V);

    return 0;
}