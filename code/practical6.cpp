// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that

#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
   private:
    unordered_map<string, vector<string>> adjList;
    unordered_map<string, unordered_map<string, bool>> adjMatrix;

   public:
    void addEdge(const string& u, const string& v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        adjMatrix[u][v] = true;
        adjMatrix[v][u] = true;
    }

    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:\n";
        for (const auto& row : adjMatrix) {
            for (const auto& pair : adjList) {
                const string& column = pair.first;
                bool hasEdge = row.second.find(column) != row.second.end() ? true : false;
                cout << (hasEdge ? "1 " : "0 ");
            }
            cout << endl;
        }
        cout << endl;
    }

    void displayAdjacencyList() {
        cout << "Adjacency List:\n";
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (const string& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void DFS(const string& start) {
        unordered_map<string, bool> visited;
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(const string& start) {
        unordered_map<string, bool> visited;
        queue<string> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            cout << node << " ";

            for (const string& neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

   private:
    void DFSUtil(const string& node, unordered_map<string, bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (const string& neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph graph;

    // Adding edges between nodes
    graph.addEdge("gate", "siem");
    graph.addEdge("gate", "strc");
    graph.addEdge("gate", "garlic");
    graph.addEdge("garlic", "siem");
    graph.addEdge("university", "olive");
    graph.addEdge("sitrc", "olive");

    // Displaying the adjacency matrix
    graph.displayAdjacencyMatrix();

    // Displaying the adjacency list
    graph.displayAdjacencyList();

    // Perform Depth-First Search (DFS) starting from node A
    cout << "DFS: ";
    graph.DFS("gate");

    // Perform Breadth-First Search (BFS) starting from node A
    cout << "BFS: ";
    graph.BFS("gate");

    return 0;
}
