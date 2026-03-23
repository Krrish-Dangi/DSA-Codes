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

struct MyQueue {
    Node* front;
    Node* rear;
    int size;

    bool isEmpty() {
        return front == NULL;
    }

    int getFront() {
        if (isEmpty()) {
            return INT_MIN;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            return INT_MIN;
        }
        return rear->data;
    }

    MyQueue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
            size++;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        size++;
        return;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return INT_MIN;
        }
        if (front == rear) {
            int data = front->data;
            delete front;
            size--;
            return data;
        }

        Node* temp = front;
        front = front->next;
        int data = front->data;
        delete front;
        size--;
        return data;
    }

    int getSize() {
        return size;
    }

};