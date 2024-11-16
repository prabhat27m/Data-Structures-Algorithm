#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;  // Maximum number of vertices

class Graph {
private:
    int adjMatrix[MAX][MAX];
    int vertices;
    

public:
    // Helper function for DFS
    void DFSUtil(int vertex, bool visited[]) {
        // Mark current vertex as visited and print it
        visited[vertex] = true;
        cout << vertex << " ";
        
        // Visit all adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
    

    Graph(int v) : vertices(v) {
        // Initialize adjacency matrix with zeros
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }
    
    // Add edge between vertices
    void addEdge(int v1, int v2) {
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;  // Remove this line for directed graph
    }
    
    // BFS traversal
    void BFS(int startVertex) {
        // Create a visited array
        bool visited[MAX] = {false};
        
        // Create a queue for BFS
        queue<int> q;
        
        // Mark the current node as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);
        
        cout << "BFS starting from vertex " << startVertex << ": ";
        
        while (!q.empty()) {
            // Dequeue a vertex and print it
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();
            
            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent has not been visited, mark it visited and enqueue it
            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
    
    // DFS traversal
    void DFS(int startVertex) {
        // Create a visited array
        bool visited[MAX] = {false};
        
        cout << "DFS starting from vertex " << startVertex << ": ";
        
        // Call the recursive helper function
        DFSUtil(startVertex, visited);
        cout << endl;
    }
    
    // Print the adjacency matrix
    void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Test the graph implementation
    int V = 6;  // Number of vertices
    Graph g(V);
    
    // Add edges for a sample graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    
    // Print the adjacency matrix
    cout << "\nGraph representation:\n";
    g.printGraph();
    
    cout << "\nGraph traversals:\n";
    // Perform BFS starting from vertex 0
    g.BFS(0);
    
    // Perform DFS starting from vertex 0
    g.DFS(0);
    
    return 0;
}