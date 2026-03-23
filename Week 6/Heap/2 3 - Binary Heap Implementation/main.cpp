#include <iostream>

using namespace std;

class MinHeap {
private:
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int capacity) {
        arr = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    void insert(int x) { // O(log(size))
        if (size == capacity) {
            return;
        }
        size++;
        arr[size-1] = x;
        int i = size-1;
        while (i != 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
};