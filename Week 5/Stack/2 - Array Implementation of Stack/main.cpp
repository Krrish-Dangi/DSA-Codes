#include <iostream>

using namespace std;

struct MyStack {
    int *arr;
    int top;
    int cap;
    MyStack(int c) {
        cap = c;
        arr = new int[c];
        top = -1;
    }

    void push(int x) {
        if (top == cap - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << boolalpha;
    cout << s.isEmpty() << endl;

    return 0;
}
