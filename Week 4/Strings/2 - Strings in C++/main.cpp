#include <iostream>
#include <string.h>

using namespace std;

int main() {
    // 1. C-style string
    char str[] = "geek";
    cout << str << endl;
    cout << strlen(str) << endl; // '\0' is added at the end by the compiler

    char str2[] {'g','e','e','k','\0'};
    cout << str2 << endl;
    cout << strlen(str2) << endl; // No '\0' is added

    int res = strcmp(str,str2);
    if (res > 0) {
        cout << "Greater";
    }else if (res == 0) {
        cout << "Equal";
    }else {
        cout << "Smaller";
    }

    cout << endl;

    char x[5];
    strcpy(x,str);
    cout << x << endl;
    cout << strlen(x) << endl;

    cout << "--------------------------------------------------------------" << endl;

    // 2. C++ String
    string str3 = "geeksforgekks";
    cout << str3.length() << endl;
    str3 = str3 + "xyz";
    cout << str3 << endl;
    cout << str3.length() << endl;
    cout << str3.substr(1,3) << endl; // [start,end]
    cout << str3.find("eek") << endl; // return string::npos if not found

    string str4 = "geeks";
    if (str3 == str4) {
        cout << "Equal";
    }else if (str3 < str4) {
        cout << "Smaller";
    }else {
        cout << "Greater";
    }

    cout << endl;

    // reading string from console
    string y;
    getline(cin,y,'a'); // if a is seen then it stops
    for (int i = 0; i < y.length(); i++) {
        cout << y[i] << endl;
    }
    cout << endl;

    for (char elem: str3) {
        cout << elem;
    }


    return 0;
}