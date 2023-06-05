// There are flight paths between cities. If there is a flight between city A and city B then there
// is an edge between the cities. The cost of the edge can be the time that flight takes to reach
// city B from A or the amount of fuel used for the journey. Represent this as a graph. The
// node can be represented by airport name or name of the city. Use adjacency list
// representation of the graph or use adjacency matrix representation of the graph. Check
// whether the graph is connected or not. Justify the storage representation used.

#include <bits/stdc++.h>
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
    int ch;
    string source;

    while (true) {
        cout << "Select the operation \n1.Add flight path \n2.bfs traversal \n3.dfs traversal \n4.displayAdjacencyMatrix \n5.displayAdjacencyList  \n6.Exit program" << endl;
        cin >> ch;

        switch (ch) {
            case 1: {
                string destination;
                cout << "Enter the source : \n";
                cin >> source;

                cout << "Enter the destination : \n";
                cin >> destination;
                graph.addEdge(source, destination);
            } break;
            case 2: {
                graph.BFS(source);
                break;
            }
            case 3: {
                graph.DFS(source);
                break;
            }
            case 4: {
                graph.displayAdjacencyMatrix();
                break;
            }
            case 5: {
                graph.displayAdjacencyList();
                break;
            }
            case 6: {
                exit(0);
            } break;
            default: {
                cout << "Invalid choice" << endl;
            } break;
        }
    }

    return 0;
}
