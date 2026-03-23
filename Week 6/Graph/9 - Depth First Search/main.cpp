#include <iostream>
#include <vector>

using namespace std;

void DFSRecursive(vector<int> graph[], int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";
    for (auto elem: graph[s]) {
        if (visited[elem] == false) {
            DFSRecursive(graph, elem, visited);
        }
    }
}

void DFSsimple(vector<int> graph[], int v, int s) {
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    DFSRecursive(graph, s, visited);
}

// If Graph is disconnected and source is not given
void DFSRecursiveDis(vector<int> graph[], int s, bool visited[]) {
    visited[s] = true;
    cout << s << " ";
    for (auto elem: graph[s]) {
        if (visited[elem] == false) {
            DFSRecursiveDis(graph, elem, visited);
        }
    }
}

void DFSdis(vector<int> graph[], int v) {
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++) {
        if (visited[i] == false)
        DFSRecursiveDis(graph, i, visited);
    }
}

// Number of islands
void DFSRecursiveDisCount(vector<int> graph[], int s, bool visited[]) {
    visited[s] = true;
    for (auto elem: graph[s]) {
        if (visited[elem] == false) {
            DFSRecursiveDisCount(graph, elem, visited);
        }
    }
}

int DFSdisCount(vector<int> graph[], int v) {
    int count = 0;
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            DFSRecursiveDisCount(graph, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> graph[] = {{1,2}, {0,3,4}, {0,3}, {1,2,4}, {1,3}};
    DFSsimple(graph, 5, 0); // O(vertex + edge) and O(vertex)
    cout << endl;

    vector<int> graph1[] = {{1,2}, {0,2}, {0,1}, {4}, {3}};
    DFSdis(graph1, 5); // O(vertex + edge) and O(vertex)
    cout << endl;

    cout << DFSdisCount(graph1, 5) << endl;
}