#include <iostream>
#include <queue> // container adapter
using namespace std;

int main() {
    cout << boolalpha;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop(); // No return (pops out first elem)
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.empty() << endl;
    cout << q.size() << endl;
    return 0;
}