#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.displayGraph();
    return 0;
}
