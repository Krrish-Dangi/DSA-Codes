#include <iostream>
#include <stack> // Container Adapted -> It is just a interface as it is defined on any other Data structure

using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    // theta(1) -> push,pop,top,size,empty
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << boolalpha;
    cout << s.empty() << endl;
    return 0;
}