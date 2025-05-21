
#include <bits/stdc++.h>
#include "io_setup.h"
using namespace std;
void printBinary(int num) {
    for (int i = 10; i >= 0;--i) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}



int main() {

    /*
    1. odo even using bit manupulation
    */
    // for (int i = 0; i < 8; ++i) {
    //     cout  << i << "->";printBinary(i);
    //     // to need to find it is odd or even we need to do & operation with 1(00000000001) (always if we take a look the ood numbers have the last bit->1 and even numbers->0) that means if the last bit 0 if we do a and with that it will be 0 and ans will be even & non-zero will be odd;
    //     // 0 - means false 
    //     // 1 - means true
    //     /*
    //         % & / it is really slow operators
    //     */
    //     if (i & 1)
    //         cout << "odd" << endl;
    //     else 
    //         cout << "even" << endl;
    // }

    // /*
    // 2. multiply and divide by 2
    // */
    // int a = 5;
    // printBinary(5);
    // /*
    // 5 -> 101(2^2+2^0->5)
    // left shift << 10 (2^2+2^0)/2 -> (2^1)
    // right shift >> 1010 (2^2+2^0)*2 -> (2^3+2^1)
    // */

    // // divide by 2 
    // cout << (a >> 1) << endl;
    // // multiply by 2
    // cout << (a << 1) << endl;


    /*
    3. lowercase to uppercase
    */
    // for(char i = 'A'; i <= 'E'; i++) {
    //     cout << i << "->";printBinary(i);
    // }
    // cout << endl;
    // for (char i = 'a'; i <= 'e'; i++) {
    //     cout << i << "->";printBinary(i);
    // }
    /*
    in the lower and upper chars there is similar pattern
    >> A - > 00001000001
    >> a -> 00001100001
    the bit after msb is set(1)
    to convert that we just need to unset or set the bit
    */
    // 
    // for (char i = 'a'; i <= 'e'; i++) {
    //     // char temp = i ^ (1 << 5); // xor 
    //     // (i&(~(1<<5))
    //     char temp = (i & (~(1 << 5)));
    //     cout << temp << "->";printBinary(i);
    // }
    // for (char i = 'a'; i <= 'e'; i++) {
    //     char temp = i | (1 << 5); // or 
    //     cout << temp << "->";printBinary(i);
    // }
    // char b = 'b';
    // // printBinary(int(b));
    // cout << char(b & '_') << endl;
    // // (1<<5) -> ASCII value of the space 
    // // ~(1<<5) ->  ~(00001100001) of this is 11111011111 so this one is not exits but we can use this 00001011111 to  unset the bit also and it '_' binary 

    // char a = 'A';
    // cout << char(a | ' ') << endl;
    /*
    4. unset all of the LSB bits
    59 -> 00000111011 convert this to 00000100000
    */

    // printBinary(59);
    // if we need to clear up till 4th bit (means total 5 bit)
    /*
    00000111011 -> 00000100000
        ^
    11111100000
        ^
    00000011111
        ^
    00000100000 - 1
    */

    // int a = 59;
    // int i = 4; // till the bit that we want to unset the bits
    // int b = (a & ~((1 << i + 1) - 1));
    // printBinary(b);
    /*
    5. unset all of the MSB bits
    59 -> 00000111011 convert this to 00000001011(clear all msb bits till 3rd bit)
    00000111011
         &
    00000001111

    00000010000 - 1
    */
    // int a = 59;
    // int i = 3; // till the bit that we want to unset the bits
    // int b = (a & ((1 << i + 1) - 1));
    // printBinary(b);


    /*
    5. check the number is 2 to power or not
    */
    int n;
    cin >> n;
    if ((n & (n - 1)))
        cout << "not to 2 to the power";
    else
        cout << "power of 2";
    return 0;
} 