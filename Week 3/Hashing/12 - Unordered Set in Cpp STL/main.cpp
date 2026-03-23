#include <iostream>
#include <unordered_set> // Handles only Keys not key:value pairs

using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    // s.insert(2); // Duplicates are not included in the set
    // for (auto elem: s) {
    //     cout << elem << " "; // Random Order
    // }

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " "; // Random Order
    }
    cout << endl;

    // cout << s.size() << endl;
    // s.clear();
    // cout << s.size() << endl;

    if (s.find(2) == s.end()) { // s.find() return end iterator if elem is not found
        cout << "Not Found" << endl;
    }else {
        cout << "Found" << " " << (*s.find(2)) <<  endl;
    }

    if (s.count(2)) { // Returns 1 or 0 (as dups are not allowed)
        cout << "Found" << endl;
    }else {
        cout << "Not Found" << endl;
    }

    s.erase(2);
    cout << s.size() << endl;

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " "; // Random Order
    }
    cout << endl;

    // OR
    // auto it = s.find(2); // if not found then infinte loop
    // s.erase(it);
    // cout << s.size() << endl;

    // Also can be used to remove range of elements
    auto it = s.find(1);
    auto it2 = s.find(2);
    s.erase(it,it2);

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " "; // Random Order
    }
    cout << endl;

    // s.erase(s.begin(), s.end());
    cout << boolalpha;
    cout << s.empty() << endl;

}
