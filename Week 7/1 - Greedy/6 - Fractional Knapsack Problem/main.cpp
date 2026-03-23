#include <algorithm>
#include <stdio.h>
#include <utility>

using namespace std;

bool myCmp(pair<int, int> p1, pair<int, int> p2) {
    double r1 = (double) p1.first/p1.first;
    double r2 = (double) p2.first/p2.first;
    return r1 > r2;
}

double fKnapSack(int W, pair<int, int> p[], int n) {
    sort(p,p+n,myCmp);
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        if (p[i].second <= W) {
            res += p[i].first;
            W -= p[i].second;
        }else {
            res += p[i].first * ((double)W/p[i].second);
            break;
        }
    }

    return res;
}