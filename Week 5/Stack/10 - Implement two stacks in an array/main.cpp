#include <iostream>

using namespace std;

class TwoStacks {
private:
    int* arr;
    int cap;
    int top1;
    int top2;

    public:
    TwoStacks(int cap) {
        this->cap = cap;
        top1 = -1, top2 = cap;
        arr = new int[cap];
    }

    bool push1(int x) {
        if (top1 < top2-1) {
           top1++;
            arr[top1] = x;
            return true;
        }else {
            return false;
        }
    }

    bool push2(int x) {
        if (top1 < top2-1) {
            top2--;
            arr[top2] = x;
            return true;
        }else {
            return false;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }else {
            return NULL;
        }
    }

    int pop2() {
        if (top2 < cap) {
            int x = arr[top2];
            top2++;
            return x;
        }else {
            return NULL;
        }
    }

    int size1() {
        return top1+1;
    }

    int size2() {
        return cap-top2;
    }

    int peek1() {
        return arr[top1];
    }

    int peek2() {
        return arr[top2];
    }
};

int main() {
    TwoStacks twoStacks(10);
    twoStacks.push1(1);
    twoStacks.push2(2);
    twoStacks.push2(3);
    twoStacks.push2(4);
    twoStacks.push1(5);
    twoStacks.push2(6);
    twoStacks.push2(7);
    twoStacks.push2(8);
    twoStacks.push1(9);
    twoStacks.push2(10);
    cout << twoStacks.peek1() << endl;
    cout << twoStacks.peek2() << endl;
    cout << twoStacks.size1() << endl;
    cout << twoStacks.size2() << endl;
    cout << twoStacks.pop1() << endl;
    cout << twoStacks.pop2() << endl;
}