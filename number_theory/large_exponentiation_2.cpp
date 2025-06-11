/**
 * Large Exponentiation with ETF & Euler's Theorem(13 14)
*/
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e7;
/*
b <= 10^9 -> RUN
b <= 10^18 -> RUN
if b value is more than 10^18 than or any value it will run
*/

int binExpIte(int a, long long b,int m) {
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
int binExpIte1(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * 1LL * a) % MOD;
        }
        a = (a * 1LL * a) % MOD;
        b >>= 1;
    }

    return ans;
}
int arrIte(vector<int>arr, int MOD) {
    int n = arr.size();
    int res = 0, power = 1;
    for (int i = n - 1; i >= 0; i--) {
        // cout << arr[i] << " " << power << " " << res << " " << (arr[i] * 10 * power) % MOD << endl;
        res += (arr[i] * power) % MOD;
        power *= 10;
    }
    return res;
}
// 2*10^2 % 1337
/**
 * (50^64^32) 1e7
 * >> in this case the b would be really big
 * >> CO-PRIME -> gcd(a,b)->1
 * ETF(EULAR TOIENT FUNCTION)
 * N -> COUNT K
 * such that  1<=K<=N
 * K,N CO-PRIME
 * 5 -> 1,2,3,4,5
 * So the count will be 4 phi(5) = 4  
*/
int main() {
    // 50^64^32 % M
    // cout << binExpIte(50, binExpIte(64, 32, MOD - 1), MOD);
    // int a, b, MOD;
    // cin >> a >> b >> MOD;
    cout << binExpIte(2147483647, arrIte({2,0,0}, 1140), 1337);
    return 0;
}