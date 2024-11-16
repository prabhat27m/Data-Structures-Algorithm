#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    vector<pair<int, int> >* adj;  // Array of vectors to store vertex and weight pairs
    int vertices;
    
public:
    Graph(int V) {
        this->vertices = V;
        adj = new vector<pair<int, int> >[V];
    }

    void addEdge(int v1, int v2, int wt) {
        adj[v1].push_back({v2, wt});
        adj[v2].push_back({v1, wt});  // Remove this line for directed graph
    }
    
    void dijkstra(int src) {
        // Create a priority queue for distances
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        
        // Create distance vector initialized to infinity
        vector<int> dist(vertices, INT_MAX);
        
        // Distance to source is 0
        dist[src] = 0;
        pq.push({0, src});  // {distance, vertex}
        
        while(!pq.empty()) {
            int u = pq.top().second;  // Current vertex
            pq.pop();
            
            // Visit all adjacent vertices of current vertex
            for(auto x : adj[u]) {
                int v = x.first;      // Adjacent vertex
                int weight = x.second; // Edge weight
                
                // If we found a shorter path to v through u
                if(dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Print the distances
        cout << "Shortest distances from source " << src << ":\n";
        for(int i = 0; i < vertices; i++) {
            if(dist[i] == INT_MAX)
                cout << i << ": INFINITY\n";
            else
                cout << i << ": " << dist[i] << "\n";
        }
    }
    
    void printGraph() {
        cout << "Adjacency List with weights:\n";
        for(int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for(auto x : adj[i]) {
                cout << "(" << x.first << "," << x.second << ") ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    Graph g(6);
    
    // Adding edges with weights: (vertex1, vertex2, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);
    
    g.printGraph();
    
    // Find shortest paths from vertex 0
    g.dijkstra(0);
    
    return 0;
}