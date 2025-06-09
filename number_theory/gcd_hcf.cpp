/** (9)
 * GCD
 * LCM
*/
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
/**
 * GCD (Greatest Common Divisor) - the highest number that can divide all of the numbers
 * LCM (Least Common Multiple) - the smallest number that is a multiple of two or more numbers.
 * [4,12] -> 4
 * [12,18] -> 6
 * PRIME FACTORIZATION[4,12]
 * 4 -> 2^2 * 3^0
 * 12 -> 2^2 * 3^1
 * GCD -> min(2^2,2^2) * min(3^0,3^1) -> 2^2 * 3^0 -> 4
 * LCM -> max(2^2,2^2) * max(3^0,3^1) -> 2^2 * 3^1 -> 12
 * [12,18]
 * 12 -> 2^2 * 3^1
 * 18 -> 2 * 3^2
 * GCD -> 2*3^1 -> 6 & LCM -> 2^2 * 3^2 -> 36
 * (a*b)/GCD = LCM
 * Euclidean algorithm -
 * https://cp-algorithms.com/algebra/euclid-algorithm.html
*/
//Euclidean algorithm
// LOG(N) -> if we divided by 2
/*
     __Quotient(res)__
Divisor ) Dividend
         - (Divisor × Quotient)
         -----------------------
             Remainder
*/
// b != 0
int gcd(int a, int b) {
    // if ((a % b) == 0) return b;
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int a, b, c;
    cin >> a >> b >> c; 
    // GCD 
    //if we even pass big number as divisor then in the next step it gonna automatically goning to dividend
    cout << "GCD->" << gcd(a, b) << endl;
    // LCM
    cout << "LCM->" << (a * b) / gcd(a, b)<<endl;
    // in buit function
    // cout << "GCD->" << __gcd(a, b) << endl;
    // for [a,b,c]
    cout << gcd(c, gcd(a, b))<<endl;
    // MINIMUM FRACTION 
    /*
    * a/b -> (a/gcd(a,b))/(b/gcd(a,b))
    */
    cout << "MINIMUM FRACTION->" << double(a / gcd(a, b)) / (b / gcd(a, b));
    return 0;
}