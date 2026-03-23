#include <iostream>
#include <stack>
using namespace std;

struct MinStack {
    stack<int> s;
    int Min;

    void push(int x) {
        if (s.empty()) {
            s.push(x);
            Min = x;
        } else if (x <= Min) {
            s.push(2*x - Min);  // encode
            Min = x;
        } else {
            s.push(x);
        }
    }

    int pop() {
        if (s.empty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        int t = s.top();
        s.pop();
        if (t <= Min) {
            int res = Min;
            Min = 2*Min - t;  // restore previous Min
            return res;
        } else {
            return t;
        }
    }

    int getMin() {
        if (s.empty()) {
            cout << "Stack empty!" << endl;
            return -1;
        }
        return Min;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Min: " << ms.getMin() << endl; // 2
    cout << "Pop: " << ms.pop() << endl;    // 2
    cout << "Min: " << ms.getMin() << endl; // 3
    cout << "Pop: " << ms.pop() << endl;    // 7
    cout << "Min: " << ms.getMin() << endl; // 3
    cout << "Pop: " << ms.pop() << endl;    // 3
    cout << "Min: " << ms.getMin() << endl; // 5
    cout << "Pop: " << ms.pop() << endl;    // 5

    return 0;
}
