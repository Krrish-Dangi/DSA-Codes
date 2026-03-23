#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>> &graph, int source, bool visited[], bool recSt[]) {
    visited[source] = true;
    recSt[source] = true;
    for (int i = 0; i < graph[source].size(); i++) {
        if (!visited[graph[source][i]] && DFS(graph, graph[source][i], visited, recSt)) {
            return true;
        }
        else if (recSt[graph[source][i]]) {
            return true;
        }
    }
    recSt[source] = false;
    return false;
}

bool detectCycle(vector<vector<int>> graph) {
    bool visited[graph.size()];
    bool recSt[graph.size()];
    for (int i = 0; i < graph.size(); i++) {
        visited[i] = false;
    }

    for (int i = 0; i < graph.size(); i++) {
        recSt[i] = false;
    }

    for (int i = 0; i < graph.size(); i++) {
        if (DFS(graph, i, visited, recSt)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {{1}, {}, {1,3}, {4}, {5}, {3}};
    cout << boolalpha << detectCycle(graph) << endl; // O(V+E)
}