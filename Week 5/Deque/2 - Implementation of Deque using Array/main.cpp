#include <iostream>

using namespace std;

struct Dequeue{
    int *arr;
    int front, cap, size;
    Dequeue(int c) {
        cap = c;
        arr = new int[cap];
        front = 0;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }

    void deleteFront() {
        if (isEmpty()) {
            return;
        }
        front = (front+1)%cap;
        size--;
    }

    void insertRear(int x) {
        if (isFull()) {
            return;
        }
        int new_rear = (front+size)%cap;
        arr[new_rear] = x;
        size++;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }else {
            return front;
        }
    }

    void insertFront(int x) {
        if (isFull()) {
            return;
        }
        front = (front+cap-1)%cap;
        arr[front] = x;
        size++;
    }

    void deleteRear() {
        if (isEmpty()) {
            return;
        }
        size--;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }else {
            return (front+size-1)%cap;
        }
    }
};

int main(){

    return 0;
}