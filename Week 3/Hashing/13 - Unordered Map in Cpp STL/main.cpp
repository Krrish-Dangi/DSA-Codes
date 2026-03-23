#include <iostream>
#include <unordered_map> // Used to store key:value, is based on hashing and is unordered
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> map;
    map["A"] = 1;
    map["B"] = 2;
    map["C"] = 3;
    map.insert({"D",4});
    map.insert(pair<string, int>("E",5));
    // for (auto elem: map) {
    //     cout << elem.first << " " << elem.second << endl;
    // }

    for (auto it = map.begin(); it != map.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }


    // Searching

    //1.
    auto it = map.find("D");
    if (it != map.end()) {
        cout << it->second << endl;
    }else {
        cout << "Not Found" << endl;
    }

    //2.
    cout << map["D"] << endl;

    //3.
    // map.erase("D");
    // cout << map.at("D") << endl; // returns error if not found

    //4.
    if (map.count("A") > 0) // returns 1 or 0 which is type of size_t
        cout << map["A"] << endl;
    else
        cout << "Not Found" << endl;


    // Size and erase functions
    cout << map.size() << endl;
    map.erase(map.begin(), map.end()); // Erases [begin, end)
    // OR map.clear()
    cout << map.size() << endl;


    return 0;
}