#include <iostream>
#include <queue>

using namespace std;

struct MyStack {
    queue<int> q1, q2;

    int top() {
        if (!q1.empty()) return q1.front();
        return -1; // or throw an exception
    }

    int getSize() {
        return q1.size();
    }

    void push(int x) {
        // Push x to empty q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20
    cout << "Size: " << st.getSize() << endl; // 2
}
