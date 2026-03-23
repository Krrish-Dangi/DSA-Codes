#include <iostream>

using namespace std;

int naive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return arr[i];
        }
    }
}

int best(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = result ^ arr[i];
    }
    return result;
}

int main() {
    int arr[] = {2,2,2,2,4,4,56};
    cout << naive(arr, 7); // TIME COMPLEXITY -- theta (n**2)

    cout << endl;
    cout << best(arr, 7); // TIME COMPLEXITY -- theta(n)


    return 0;
}