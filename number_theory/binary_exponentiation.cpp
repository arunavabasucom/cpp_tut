/**
 * Binary Exponentiation (10 11)  
 */
#include <io_setup.h>
 #include <bits/stdc++.h>
using namespace std;
const int MOD = 1e7; // it make sure the the number is alwasys within that
/**
     * Binary Exponentiation RECURSIVE
     * DIVIDE AND CONCUR a^b (if b is odd then a*(a^b-1))
     * 2^16 = 2^8 * 2^8
     * 2^8 = 2^4 * 2^4
     * 2^4 = 2^2 * 2^2
     * 2^2 = 2^1 * 2^1
     * >> we can do the same operation in 4 steps >> log2(b)
     * >> f(a,b) -> a^b
     * >> f(a,b) -> f(a,b/2) * f(a,b/2) (b = EVEN)
     * >> f(a,b) -> a * f(a,b/2) * f(a,b/2) (b = ODD)
*/
int binExpRecur(int a, int b) {
    if (b == 0) return 1;
    long long  res = binExpRecur(a, b / 2);
    if (b & 1) {
        return(a * ((res * 1LL * res) % MOD) % MOD); // the calculation is going to be in long long but we do the moduleo to get it in the range   
    }
    else {
        return ((res * 1LL*res) % MOD);
    }
}

/**
 * ITERATIVE METHOD
 * 3^13 -> 3^(1101)BASE2  -> 3(8+4+0+1) -> 3^8 * 3^4 * 3^2 * 3^1
 * a,b(power) -> log(b)
 * 
*/
int binExpIte(int a, int b) {
    int ans = 1;
    while (b){
        if (b & 1) {
            ans = (ans *1LL* a)%MOD;
        }
        a = (a * 1LL* a)%MOD;
        b >>= 1;
    }
    
    return ans;
}
int main() {
    // double d = 1e24; // somecases the double can not store the numbers super precisely
    // how many number going to print after .
    // cout << fixed << setprecision(30) << d;
    // pow(2, 3); // it returns double
    /**
     * calculating power in O(N)
    */
    int a, b, ans = 1;
    cin >> a >> b;
    // for (int i = 0; i < b; i++) { 
    //     ans *= a;
    //     ans %= MOD;
    // }
    // cout << ans << endl;

    
    cout << binExpRecur(a, b) << endl;
    cout << binExpIte(a, b);
    return 0;
}  