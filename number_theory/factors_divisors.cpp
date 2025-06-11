/**
 * Basics of Factors and Divisors (15)
*/
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,count=0,sum=0;
    cin >> n;
    // divisors - ITERATIVE APPORACH(O(N)) 
    // for (int i = 0; i <= n; i++) {
    //     if (n % i == 0) {
    //         count++;
    //         sum += i;
    //         cout << i << endl;
    //     }

    // }
    // divisors - ITERATIVE APPORACH(O(squrt(n)))  
    // i <= sqrt(n); or i*i <= n
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " "<< n/i<<endl;
            count += 1;
            sum += i;
            if ((n / i) != i) {
                sum += n / i;
                count += 1;
            }
        }
    }
 
    cout << count << " " << sum;
    return 0;
}