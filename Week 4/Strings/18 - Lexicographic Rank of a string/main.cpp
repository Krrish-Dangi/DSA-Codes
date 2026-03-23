#include <iostream>
using namespace std;

const int CHAR = 256;

// Function to calculate factorial
int fac(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Function to find lexicographic rank of a string
int lexRank(string str) {
    int res = 1;
    int n = str.length();
    int mul = fac(n);
    int count[CHAR] = {0};

    // Store frequency of each character
    for (int i = 0; i < n; i++) {
        count[str[i]]++;
        if (count[str[i]] > 1) {
            // If duplicate character → rank not well-defined
            return -1;
        }
    }

    // Convert count[] to prefix sum array
    for (int i = 1; i < CHAR; i++) {
        count[i] += count[i - 1];
    }

    // Calculate rank
    for (int i = 0; i < n - 1; i++) {
        mul = mul / (n - i);
        res += count[str[i] - 1] * mul;

        // Reduce count[] for characters >= str[i]
        for (int j = str[i]; j < CHAR; j++) {
            count[j]--;
        }
    }

    return res;
}

int main() {
    string s = "STRING";
    int rank = lexRank(s); // O(n)

    if (rank == -1)
        cout << "Duplicate characters not allowed!" << endl;
    else
        cout << "Lexicographic Rank of " << s << " is: " << rank << endl;

    return 0;
}
