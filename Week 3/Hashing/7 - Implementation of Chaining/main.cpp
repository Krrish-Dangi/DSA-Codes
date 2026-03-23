#include <iostream>
#include <list>

using namespace std;

struct MyHash {
    int BUCKET;
    list<int> *table; // Doubly linked list

    MyHash(int b) {
        BUCKET = b;
        table = new list<int>;
    }

    void insert(int key) {
        int index = key % BUCKET;
        table[index].push_back(key);
    }

    void remove(int key) {
        int i = key % BUCKET;
        table[i].remove(key);
    }

    bool search(int key) {
        int i = key % BUCKET;
        for (auto x: table[i]) {
            if (x == key)
                return true;
        }
        return false;
    }
};
