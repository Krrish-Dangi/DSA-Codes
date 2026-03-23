#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> &graph, int start) {
    bool visited[graph.size()];
    for (int i = 0; i < graph.size(); ++i) {
        visited[i] = false;
    }
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// BFS CODE where NO source is passed and graph might be disconnected
void BFSnew(vector<vector<int>> &graph, int start, bool visited[]) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSdis(vector<vector<int>> &graph) {
    bool visited[graph.size()];
    for (int i = 0; i < graph.size(); ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            BFSnew(graph, i, visited);
        }
    }
}

// Find number of connected components in an undirected graph (Number of islands)
void Helper(vector<vector<int>> &graph, int start, bool visited[]) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // cout << u << " ";
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int NumberOfIslands(vector<vector<int>> &graph) {
    int count = 0;
    bool visited[graph.size()];
    for (int i = 0; i < graph.size(); ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            Helper(graph, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> graph = {{1,2},{0,2,3}, {0,1,3,4}, {1,2,4}, {2,3}};
    BFS(graph, 0);

    cout << endl;

    vector<vector<int>> graphdis = {{1,2}, {0,3}, {0,3}, {1,2}, {5,6}, {4,6}, {4,5}};
    BFSdis(graphdis); // O(vertex + edge)
    cout << endl;
    cout << NumberOfIslands(graphdis) << endl;

}