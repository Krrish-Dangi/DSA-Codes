#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> q = {10,20,30};
    q.push_front(5);
    q.push_back(50);
    for (auto x: q) { // Random Access only in C++ STL
        cout << x << endl;
    }
    cout << q.front() << endl;
    cout << q.back() << endl;

    auto it = q.begin();
    it++;
    q.insert(it, 30); // pushes 30 before it and O(n)
    q.pop_front();
    q.pop_back();
    q.erase(q.begin(), q.end()); // O(n)
    cout << q.size() << endl;

    return 0;
}