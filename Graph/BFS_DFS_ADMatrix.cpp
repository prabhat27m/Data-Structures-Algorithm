#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<int>* adj;  // Array of vectors
    int vertices;
    
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        
        // Visit all adjacent vertices
        for(int x : adj[vertex]) {
            if(!visited[x]) {
                DFSUtil(x, visited);
            }
        }
    }
    
public:
    Graph(int V) {
        this->vertices = V;
        adj = new vector<int>[V];  // Create array of V vectors
    }

    void addEdge(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);  // Remove this line for directed graph
    }
    
    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        
        visited[startVertex] = true;
        q.push(startVertex);
        
        cout << "BFS starting from vertex " << startVertex << ": ";
        
        while(!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();
            
            for(int x : adj[currentVertex]) {
                if(!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }
    
    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);
        cout << "DFS starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }
    
    void printGraph() {
        cout << "Adjacency List:" << endl;
        for(int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for(int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free memory
    ~Graph() {
        delete[] adj;
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    
    g.printGraph();
    g.BFS(0);
    g.DFS(0);
    
    return 0;
}