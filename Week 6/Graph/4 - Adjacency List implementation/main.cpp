#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // since, undirected graph
}

int main() {
    int v = 4;
    vector<int> adjList[v];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);

    return 0;
}