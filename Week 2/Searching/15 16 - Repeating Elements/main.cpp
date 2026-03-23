// max(arr) tk saare nuumbers rahenge
// Zero hamesha rahega
// Koi ek hi element repeat krega
// 0 <= max(arr) <= n-2

#include <iostream>

using namespace std;

int findRepeatingElement(int arr[], int n) { // O(n) and O(n)
    bool flag[n-1]{false};
    for (int i = 0; i < n; i++) {
        if (flag[arr[i]]) {
            return arr[i];
        }
        flag[arr[i]] = true;
    }
    return -1;
}


int best(int arr[], int n) {
    // Phase 1 (fast is twice fast)
    int slow = arr[0]+1, fast = arr[0]+1;
    do {
        slow = arr[slow]+1;
        fast = arr[arr[fast]]+1;
    }while (slow != fast);

    // Phase 1 (Same Pace)
    slow = arr[0]+1;
    while (slow != fast) {
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }
    return slow-1;
}


int main() {
    int arr[]{0,2,1,3,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findRepeatingElement(arr, n) << endl;

    int arr1[]{0,2,1,3,2,2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << findRepeatingElement(arr1, n) << endl;
}