#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;
    vector<vector<pii>> adj; // pair<vertex, weight>

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << i << " -> " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 4, 4);

    g.dijkstra(0);
    return 0;
}
