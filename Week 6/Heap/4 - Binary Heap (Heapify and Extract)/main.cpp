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

    void insert(int x) { // O(log(n))
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

    void minHeapify(int i) { // O(height) or O(log(n)) and O(log(n))
        int l = left(i);
        int r = right(i);
        int smallest;
        if (l < size && arr[l] < arr[i]) {
            smallest = l;
        }
        if (r < size && arr[r] < arr[i]) {
            smallest = r;
        }
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin() { // O(log(n)) and O(log(n))
        if (size == 0) {
            return INT_MIN;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size-1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
};