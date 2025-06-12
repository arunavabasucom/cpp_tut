/**
 * Prime Check & Prime Factorisation(16)
 */
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
    // n -> 1 n if n has two divisors then it called prime number
    int n;
    cin >> n;    
    // bool is_prime = true;
    // if (n == 1){
    //     cout << "non-prime";
    //     return 0;
    // }
    // // O(N)
    // // for (int i = 2; i < n; ++i) {
    // //     if (n % i == 0) {
    // //         is_prime = false;
    // //         break;
    // //     }
    // // }
    // //O(sqrt(n))
    // for (int i = 2; i * i  <=n; ++i) {
    //     if (n % i == 0) {
    //         is_prime = false;
    //         break;
    //     }
    // }

    // if (is_prime) {
    //     cout << "prime";
    // }  
    // else {
    //     cout << "non-prime";
    // }

    /**
     * PRIME FACTORS(O(N))->every number smallest divisors are always prime
     * there is atlest one prime number before sqrt(n) -> for composite numbers
    */

    vector<int>prime_factors;
    // for (int i = 2; i <= n;i++) {
    //     while (n % i == 0) {
    //         prime_factors.push_back(i);
    //         n /= i;
    //     }
    // }
    // O(sqrt(n)) 
    for (int i = 2; i * i <= n;i++) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        prime_factors.push_back(n);
    }
    for (int num : prime_factors) {
        cout << num << " ";
    }


}