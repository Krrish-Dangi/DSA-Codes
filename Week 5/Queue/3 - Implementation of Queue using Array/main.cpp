#include <iostream>

using namespace std;

struct MyQueue {
    int *arr;
    int front, size, capacity;

    MyQueue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = 0;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }else {
            return arr[front];
        }
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }else {
            return (front + size - 1) % capacity;
        }
    }

    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        int rear = getRear();
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }
};

int main(){

    return 0;
}