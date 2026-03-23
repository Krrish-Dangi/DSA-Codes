#include <iostream>
using namespace std;

struct kStacks {
    int *arr, *top, *next;
    int k, free_top, cap;
    kStacks(int n, int k1) {
        free_top = 0;
        cap = n;
        k = k1;
        arr = new int[n];
        top = new int[k];
        fill(top,top+k,-1);
        for (int i = 0; i < cap-1; i++) {
            next[i] = i+1;
        }
        next[cap-1] = -1;
    }

    void push(int sn, int x) {
        int i = free_top;
        free_top = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn) {
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free_top;
        free_top = i;
        return arr[i];
    }

    bool isEmpty(int sn) {
        return top[sn] == -1;
    }
};