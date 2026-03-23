#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void ShortestPath(vector<vector<int>> graph, int source) {
    bool visited[graph.size()];
    for (int i = 0; i < graph.size(); i++) {
        visited[i] = false;
    }
    int dist[graph.size()]; // **
    queue <int> q;
    q.push(source);
    dist[source] = 0; // **
    visited[source] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < graph[curr].size(); i++) {
            if (!visited[graph[curr][i]]) {
                dist[graph[curr][i]] = dist[curr] + 1; // **
                visited[graph[curr][i]] = true;
                q.push(graph[curr][i]);
            }
        }
    }

    for (auto elem: dist) {
        cout << elem << " ";
    }
}

int main() {
    vector<vector<int>> graph = {{1,2}, {0,2,3}, {0,1,3}, {1,2}};
    ShortestPath(graph, 0);
}