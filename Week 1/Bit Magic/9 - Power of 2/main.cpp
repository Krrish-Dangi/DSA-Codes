#include <iostream>
#include <iomanip>

using namespace std;

bool best(int n) {
    if (n == 0) {
        return false;
    }
    return (n&(n-1)) == 0; // Since the powers 2 has only 1 set bits
// subtracting by 1 toggles the only set bit to zero and all the right bits to 1
}

int main() {
    cout << boolalpha;
    cout << best(6) << endl;
    cout << best(8) << endl;
    cout << best(4) << endl;
    cout << best(16) << endl;


}