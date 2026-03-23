#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq; // MAX HEAP BY DEFAULT
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout << pq.size() << endl;
    cout << pq.top() << endl;
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    // PQ AS MIN HEAP
    // OR
    // multiply array elements with -1 and build a MAX HEAP and print -pq.top()
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10); // O(logn)
    pq2.push(15);
    pq2.push(5);
    cout << pq2.size() << endl;
    cout << pq2.top() << endl;
    while (!pq2.empty()) {
        cout << pq2.top() << endl;
        pq2.pop();
    }

    // PQ using existing vector or array
    int arr[] {10,5,15};
    priority_queue<int> pq3(arr,arr+3); // O(n) better than individual pushing
    while (!pq3.empty()) {
        cout << pq3.top() << endl;
        pq3.pop(); // O(logn)
    }

}