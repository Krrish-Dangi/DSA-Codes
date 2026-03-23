#include <iostream>

using namespace std;

int sum1(int* array,int n, int sum) {
    if (n == 0) {
        return (sum == 0) ? 1 : 0;
    }
    return sum1(array,n-1,sum) + sum1(array,n-1,sum-array[n-1]);

}

int main() {
    int arr[]{10,20,15};
    cout << sum1(arr,3,25) << endl; // theta(2**n)

    return 0;
}