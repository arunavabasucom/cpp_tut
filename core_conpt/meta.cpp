/*
META PROGRAMMING -
1. Template
2. constexpr
3. using MACROS 
*/
#include <iostream>
using namespace std;
// using templete it is computed in the compile time
// template <int N>
// struct Factorial {
//      static const int value = N * Factorial<N - 1>::value;
// };
// template<>
// struct Factorial<0> {
//     static const int value = 1;
// };
constexpr int square(int x) {
    return x * x;
}

int main() {
    // const int result = Factorial<5>::value;
    // cout << result;
    cout << square(10);
}