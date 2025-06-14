/**
 * Modular Multiplicative Inverse(19)
*/
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int modulerInverse(int a, long long b, int m) {
    // but we can directly pass b value to 10^18
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1; // doing righ sihft every time log(b) times       
    }
    return ans;
}
/**
 * There are N children and K toffees.K < N, Count the number of ways to distribute toffee among N students such that each student get 1 toffee->nCk
 * N < 10^9, K<N<10^9 , %M , M=10^9+7
 * for Q queries also Q<10^5 
 * n!/((n-r)!*r!)
*/

 
const int N = 1e6 + 7;
int fact[N];
int main() {
/**
     * a*b=1
     * b is MI of a
     * (a*b)%M = 1
     * b is MMI of a
     * 1<=b<M-1
     * (a%M * b%M)%M =1
     * we can find MMI only is a and M is co-prime.
*/
    // cout << inverse(n, MOD - 2, MOD);
    fact[0] = 1;
    for (int i = 1; i < N;i++) {
        fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    }
    int q;
    cin >> q;
    while (q--) {
        int n,k;
        cin >> n >> k;
        int ans = fact[n];
        int dect = ((fact[n - k] * fact[k])%MOD);
        ans = (1LL * ans * modulerInverse(dect, MOD - 2, MOD)) % MOD;
        cout << ans << endl;
    }

    return 0;
}