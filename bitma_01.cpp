#include <bits/stdc++.h>
using namespace std;


void printBinary(int num) {
    for (int i = 10; i >= 0;--i) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
int main() {
    int a = 7;
    printBinary(a);
    int i = 0;
    if (a & ((1 << i) != 0)) {
        cout << "set\n";
    }
    else {
        cout << "not set\n";
    }
    // to set bit at ith bit we need to OR
    printBinary(a | (1 << 3));
    // to unset a bit at ith postion we need to AND with inverted binary
    printBinary(a&(~(1 << 1)));
    // to toggle we need to perform XOR
    printBinary(a ^ (1 << 1));

    int ct = 0;
    for (int i = 31; i >= 0; i--) {
        if ((a & (1 << i)) != 0) {
            ct++;            
        }
    }
    cout << ct;

    // built in functions
    cout << __builtin_popcount(a);
    cout << __builtin_popcountll((1LL<<35)-1);


    return 0;
}