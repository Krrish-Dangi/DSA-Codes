#include <iostream>
#include <deque>

using namespace std;

int better(int petrol[], int dist[], int n) {
    deque<int> dq;
    int start = 0;
    int curr_petrol = 0;
    int count = 0;

    int i = 0;
    while (count < n && i < 2 * n) {
        int idx = i % n;
        curr_petrol += petrol[idx] - dist[idx];
        dq.push_back(idx);
        count++;

        while (curr_petrol < 0 && !dq.empty()) {
            int removed = dq.front();
            dq.pop_front();
            curr_petrol = 0;
            count = 0;
            for (int j : dq) {
                curr_petrol += petrol[j] - dist[j];
                count++;
            }
        }

        if (count == n) return dq.front() + 1;

        i++;
    }
    return -1;
}

int CircularTour(int petrol[], int dist[], int n) {
    int start = 0;
    int curr_petrol = 0;
    int prev_petrol = 0;

    for (int i = 0; i < n; i++) {
        curr_petrol += petrol[i] - dist[i];
        if (curr_petrol < 0) {
            start = i + 1;
            prev_petrol += curr_petrol;
            curr_petrol = 0;
        }
    }

    return (curr_petrol + prev_petrol) >= 0 ? start + 1 : -1;
}


int main() {
    int petrol[]{4, 8, 7, 4};
    int dest[]{6, 5, 3, 5};

    cout << "Deque-based solution (better): " << better(petrol, dest, 4) << endl; // O(n) and O(n)
    cout << "Efficient linear solution: " << CircularTour(petrol, dest, 4) << endl; // O(n)

    return 0;
}
