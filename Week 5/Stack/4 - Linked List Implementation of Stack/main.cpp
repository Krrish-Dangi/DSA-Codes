#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct MyStack {
    Node* head;
    int size;
    MyStack() {
        head = NULL;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }

    int pop() {
        if (head == NULL) return INT_MIN;
        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    int Size() {
        return size;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    int peek() {
        return head->data;
    }
};

int main() {
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.pop() << endl;
    cout << stack.peek() << endl;
    cout << boolalpha;
    cout << stack.isEmpty() << endl;
    cout << stack.Size() << endl;

    return 0;
}
