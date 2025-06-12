/**
 * Sieve Algorithm & Variations(17 18)
*/
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
// Q < 10^7,N < 10^7 -> O(10^sqrt(10^7))
// const int N = 1e7 + 10;
const int N = 1e5 + 10;
vector<bool> is_prime(N, 1);
vector<int> lp(N, 0), hp(N, 0);
int main() {
    // is_prime[0] = is_prime[1] = false;
    // normally
    // N*log(N)
    // with if condition
    // N*(log(log(N)))
    // optimiztion -> i*i < N , j = i*i
    // for (int i = 2; i < N;i++) {
    //     if (is_prime[i] == true) {
    //         for (int j = 2 * i; j < N; j += i) {
    //             is_prime[j] = false;
    //         }
    //     }        
    // } 
    // for (int i = 0; i <= 100; i++) {
    //     cout << is_prime[i] << endl;
    // }
    //  Q*O(N) -> Q*O(1)
    // int q;
    // cin >> q;
    // while (q--) {
    //     int num;
    //     cin >> num;
    //     if (is_prime[num] == true) {
    //         cout << "prime"<<endl;
    //     }
    //     else {
    //         cout << "non-prime"<<endl;
    //     }            
    // }

    /**
     * LOWEST AND HIGHEST PRIME
    */
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i < N;i++) {
//         if (is_prime[i] == true) {
//             lp[i] = hp[i] = i;
//             for (int j = 2 * i; j < N; j += i) {
//                 is_prime[j] = false;
//                 hp[j] = i;
//                 if (lp[j] == 0) {
//                     lp[j] = i;
//                 }
//             }
//         }
        
// } 
// for (int i = 2; i <= 100; i++) {
//     cout << lp[i] << " "<< hp[i] << endl;
// }

/**
 * PRIME FACTORS ->  log(N)
*/
 
// int num;
// cin >> num;
// // vector<int> prime_factors;
//  map<int, int> prime_factors; // or we can use unorderd map
// while (num > 1) {
//     int prime_factor = hp[num];
//     if (num % prime_factor == 0) {
//         num /= prime_factor;
//         // prime_factors.push_back(prime_factor);
//         prime_factors[prime_factor]++;
//     }
// }
// for (auto num : prime_factors){
//     // cout << num << endl;
//     cout << num.first << " " << num.second << endl;

// }

/**
 * DIVISORS
*/

vector<int> divisors[N];
for (int i = 2; i < N;i++) {
    for (int j = i; j < N; j += i) {
        divisors[j].push_back(i);
    }
}
for (int i = 1; i < 10;++i) {
    for (int div : divisors[i]) {
        cout << div<<" ";
    }
    cout << endl;
}

return 0;
}