#include <iostream>

using namespace std;

// Does Less Memory Writes compared to other sort. BEST IS CYCLE SORT though
void SelectionSort(int arr[], int n) { // Unstable and in-place (means we dont use any auxiliary array)
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main() {
    int arr[]{10,5,8,20,2,18};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n); // O(n**2), Unstable, In-Place and does less memory writes
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}