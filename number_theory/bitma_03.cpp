/*(6)
XOR operator
0 0 -> 0
0 1 -> 1
1 0 -> 1
1 1 -> 0

>> x ^ x -> 0 (101^101->0)
>>  x ^ 0 -> x 
>> x ^ y ^ z -> x ^ z ^ y -> y ^ x ^ z

*/
#include <bits/stdc++.h>
#include <io_setup.h>
using namespace std;

int main(){
    /**
     * 1. swap 2 numbers using xor
    **/
    // int a = 4; int b = 6;
    // a = a ^ b;
    // // b = b ^ (a ^ b) = a;
    // b = b ^ a;
    // // a = (a ^ b) ^ b;
    // // a = (a ^ b) ^ a; // => b = a
    // // a = b;
    // a = a ^ b;
    // cout << a << b;

    /**
     * 2. Given array a of n integers. All integers
     * are present in event count except one.
     * Find that one integer which has odd count
     * in O(N) time complexity and 0(1) space;
     * N < 10^ 5
    * a[i] < 10^5
    **/
    int N,ans = 0;
    cin >> N;
    for (int i = 0;i < N; i++) {
        int temp;
        cin >> temp;
        ans ^= temp;
    }
    cout << ans;
    return 0;
}