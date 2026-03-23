#include <iostream>

using namespace std;

double findMedian(int arr1[], int n1, int arr2[], int n2) {
    int begin1 = 0;
    int end1 = n1;
    while (begin1 <= end1) {
        int i1 = (begin1 + end1) / 2;
        int i2 = ((n1+n2+1)/2) - i1;

        int min1 = (i1==n1)?INT_MAX:arr1[i1]; // Right side of a1 ka min
        int max1 = (i1==0)?INT_MIN:arr1[i1-1]; // Left side of a1 ka max

        int min2 = (i2==n2)?INT_MAX:arr2[i2]; // Right side of a2 ka min
        int max2 = (i2==0)?INT_MIN:arr2[i2-1]; // Left side of a2 ka max

        if (max1 <= min2 && max2 <= min1) {
            if ((n1+n2)%2 == 0) {
                return ((double) max(max1,max2) + min(min1,min2))/2;
            }else {
                return ((double) max(max1,max2));
            }
        }else if (max1>min2) {
            end1 = i1-1;
        }else {
            begin1 = i1+1;
        }
    }
}

int main() {
    int a1[]{10,20,30};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int a2[]{5,15,25,35,45};
    int n2 = sizeof(a2)/sizeof(a2[0]);
    cout << findMedian(a1,n1,a2,n2) << endl; // O(log n)
}