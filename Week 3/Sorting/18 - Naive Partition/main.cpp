// Partition element se chota left m and bada right m

#include <iostream>

using namespace std;

void naive(int arr[], int l, int h, int p) {
    int res[h-l+1];
    int index = 0;
    for (int i = l; i <= h; i++) {
        if ((arr[i] < arr[p]) && (i != p)) {
            res[index] = arr[i];
            index++;
        }
    }

    res[index++] = arr[p];

    for (int i = l; i <= h; i++) {
        if (arr[i] > arr[p]) {
            res[index] = arr[i];
            index++;
        }
    }
    for (int i = l; i <= h; i++) {
        arr[i] = res[i-l];
    }
}

int main() {
    int arr[]{5,13,6,9,12,11,8};
    naive(arr, 0, 6, 6);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }

}