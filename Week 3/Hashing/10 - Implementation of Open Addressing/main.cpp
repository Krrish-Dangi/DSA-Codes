#include <iostream>

using namespace std;

class MyHash {
private:
    int *hashTable;
    int size,cap;

public:
    MyHash(int x): cap{x}, size{0} {
        hashTable = new int[cap];
        for (int i = 0; i < cap; i++) {
            hashTable[i] = -1;
        }
    }

    int hash(int key) {
        return key % cap;
    }

    bool insert(int key) {
        if (size == cap) {
            return false;
        }
        int i = hash(key);
        while (hashTable[i] != -1 && hashTable[i] != key && hashTable[i] != -2)
            i = (i+1) % cap;
        if (hashTable[i] == key) {
            return false;
        }else {
            hashTable[i] = key;
            size++;
            return true;
        }
    }

    bool search(int key) {
        int h = hash(key);
        int i = h;
        while (hashTable[i] != -1) {
            if (hashTable[i] == key) {
                return true;
            }
            i = (i+1) % cap;
            if (i == h) {
                return false;
            }
        }
        return false;
    }

    bool del(int key) {
        int h = hash(key);
        int i = h;
        while (hashTable[i] != -1) {
            if (hashTable[i] == key) {
                hashTable[i] = -2;
                size--;
                return true;
            }
            i = (i+1) % cap;
            if (i == h) {
                return false;
            }
        }
        return false;
    }
};

int main() {
    MyHash table{6};
    table.insert(5);
    table.insert(7);
    table.insert(9);
    cout << boolalpha;
    cout << table.search(5) << endl;
    cout << table.search(7) << endl;
    table.del(7);
    cout << table.search(7) << endl;
    return 0;
}