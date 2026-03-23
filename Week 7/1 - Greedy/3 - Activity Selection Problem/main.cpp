#include <algorithm>
#include <iostream>

using namespace std;

bool myCmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int maxActivites(pair<int,int> arr[], int n) {
    sort(arr,arr+n,myCmp);
    int prev = 0;
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i].first >= arr[prev].second) {
            res++;
            prev = i;
        }
    }

    return res;
}

int main() {
    pair<int,int> arr[] = {pair<int,int>(3,8), pair<int,int>(2,4), pair<int,int>(1,3), pair<int,int>(10,11)};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxActivites(arr, n) << endl;
    return 0;

}