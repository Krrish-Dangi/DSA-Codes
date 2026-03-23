#include <iostream>
using namespace std;

void cycleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int item = arr[i];
        int pos = i;

        // Find correct position for item
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < item) {
                pos++;
            }
        }

        // If item is already in correct position, skip
        if (pos == i) continue;

        // Handle duplicates
        while (item == arr[pos]) {
            pos++;
        }

        // Place item to correct position
        swap(item, arr[pos]);

        // Rotate the rest of the cycle
        while (pos != i) {
            pos = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < item) {
                    pos++;
                }
            }

            while (item == arr[pos]) {
                pos++;
            }

            swap(item, arr[pos]);
        }
    }
}

int main() {
    int arr[]{20, 40, 50, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cycleSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
