#include <deque>
#include <iostream>

using namespace std;

struct MyDS {
    deque<int> dq;
    void insertMin(int x) {
        dq.push_front(x);
    }

    void insertMax(int x) {
        dq.push_back(x);
    }

    int getMin() {
        return dq.front();
    }

    int getMax() {
        return dq.back();
    }

    int extractMin() {
        int min = dq.front();
        dq.pop_front();
        return min;
    }

    int extractMax() {
        int max = dq.back();
        dq.pop_back();
        return max;
    }
};

int main() {

    return 0;
}