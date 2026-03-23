#include <algorithm>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool myComp(Interval a, Interval b) {
    return a.start < b.start;
}

void best(Interval arr[], int n) {
    sort(arr, arr + n, myComp);
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (arr[res].end >= arr[i].start) {
            arr[res].end = max(arr[res].end, arr[i].end);
            arr[res].start = min(arr[res].start, arr[i].start);
        }else {
            res++;
            arr[res] = arr[i];
        }
    }
    for (int i = 0; i <= res; i++) {
        cout << arr[i].start << " " << arr[i].end << endl;
    }
}

int main() {
    Interval intervals[]{{5,10},{3,15},{18,30},{2,7}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    best(intervals, n); // theta(nlogn)
}