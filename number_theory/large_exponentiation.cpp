/**
 * Large Exponentiation(12)
 */
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e18;
// contraints -> a <= 10^9,b <= 10^9,MOD <= 10^9
// if -> a > 10^9 or MOD > 10^9
// a <= 10^18 || 2^1024
// MOD = 10^18 then it may overflow
// log^2(N)
int binExpIte(int a, int b) {
    // a %= MOD;
    // a = binExp(2, 1024);
     // a^b % M = ((a%M)^b)%M
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = binMultiply(ans, a);
        }
        a = binMultiply(a,a);
        b >>= 1;
    }
    return ans;
}
/*
>> ITERATIVE APPOROACH(O(N))
a*a -> 10^18 (a->10^18)
a+a...atimes
a->10^18
a+a<2*10^18
(a+a)%MOD < 10^18

>> BINARY MULTIPLY(O(log(N)))
a*(b)
3*(13)
3*(1101)BASE2
3*(8+4+0+1)
*/
int binMultiply(long long a , long long b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % MOD; 
        }
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << binExpIte(a, b);
    return 0;
}