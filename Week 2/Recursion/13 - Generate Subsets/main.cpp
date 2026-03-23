#include <iostream>

using namespace std;

void printSubsets(string s,string curr,int index = 0) {
    if (index == s.length()) {
        cout << curr << endl;
        return ;
    }
    printSubsets(s, curr, index+1);
    printSubsets(s, curr+s[index], index+1);


}

int main(){
    printSubsets("ABC","");

    return 0;
}