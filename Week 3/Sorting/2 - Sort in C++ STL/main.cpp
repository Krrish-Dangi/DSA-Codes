#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
    int x, y;
};

bool myComp(point a, point b) {
    return a.x < b.x;
}

int main() {
    // int arr[]{10,20,5,7};
    // sort(arr, arr + 5);
    // for (int x: arr) {
    //     cout << x << " ";
    // }
    // sort(arr, arr + 4, greater<int>()); // Decreasing order
    // cout << endl;
    // for (int x: arr) {
    //     cout << x << " ";
    // }

    // vector<int> v{5,7,20,10};
    // sort(v.begin(), v.end());
    // for (int x:v) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // sort(v.begin(), v.end(), greater<int>());
    // for (int x:v) {
    //     cout<<x<<" ";
    // }

    point arr[]{{3,10}, {2,8}, {5,4}};
    sort(arr,arr+3,myComp); // Uses IntroSort(Hybrid of Quick, Heap and Insertion Sort)
    for (int i = 0; i < 3; i++) {
        cout << arr[i].x << " " << arr[i].y << endl;
    }
    // T.C. :- O(nlogn)
}