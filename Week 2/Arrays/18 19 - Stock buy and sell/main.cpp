#include <iostream>

using namespace std;

int naive(int price[], int start, int end) {
    if (end <= start) {
        return 0;
    }
    int profit = 0;
    for (int i = start; i <= end; i++) {
        for (int j = i+1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr_profit = price[i] - price[j] + naive(price, start, i - 1) + naive(price, j+1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
}

int best(int price[], int n) {
    int profit = 0;
    for (int i = 1; i < n; i++) {
        if (price[i] > price[i-1]) {
            profit += price[i] - price[i-1];
        }
    }
    return profit;
}

int main() {
    int arr[]{1,5,3,8,13};
    cout << naive(arr, 0, 5) << endl;
    int arr1[]{1,5,3,8,13};
    cout << best(arr1, 5) << endl; // theta(n)
}