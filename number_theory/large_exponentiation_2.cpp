#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e7;
/*
b <= 10^9 -> RUN
b <= 10^18 -> RUN
if b value is more than 10^18 than or any value it will run
*/

int binExpIte(int a, long long b) {
    // but we can directly pass b value to 10^18
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * 1LL * a) % MOD;
        }
        a = (a * 1LL * a) % MOD;
        b >>= 1; // doing righ sihft every time log(b) times       
    }

    return ans;
}
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
    return 0;
}