// Find two elements which sum up to a given element (Array is Salted)

#include <iostream>

using namespace std;

bool isPair(int arr[], int n, int x) {
    int i = 0, j = n-1;
    while (i<=j) {
        if ((arr[i]+arr[j]) == x) {
            return true;
        }else if ((arr[i]+arr[j]) < x) {
            i++;
        }else {
            j--;
        }
    }
    return false;
}

int main() {
    int arr[]{2,4,8,9,11,12,20,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << boolalpha;
    cout << isPair(arr, n, 23) << endl;
}