#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


bool DFSRec(vector<vector<int>> graph, int source, bool visited[], int parent) {
    visited[source] = true;
    for (int i = 0; i < graph[source].size(); i++) {
        if (!visited[graph[source][i]]) {
            if (DFSRec(graph, graph[source][i], visited, source)) {
                return true;
            }
            else if (graph[source][i] != parent) {
                return true;
            }
        }
    }
    return false;
}

bool checkLoop(vector<vector<int>> graph) { // O(V+E) and O(Vertex)
    bool visited[graph.size()];
    for (int i = 0; i < graph.size(); i++) {
        visited[i] = false;
    }

    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            if (DFSRec(graph, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {{1}, {0,2,3}, {1,3,4}, {1,2}, {2,5}, {4}};
    bool result = checkLoop(graph);
    cout << boolalpha << result << endl;
}
