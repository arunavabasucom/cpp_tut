/**
 * (7)
 * BITMASKING -> BIT + MASKING
 * https://codeforces.com/blog/entry/73558
**/
#include <bits/stdc++.h>
#include <io_setup.h>
using namespace std;

/**
 * Apple - 0
 * Orange - 1
 * Bannana - 2
 * Lichi - 3

 * 1 - [2,3] -> 1100(12)(2 and 3  bit is set so it is the representation for the array) it is called BITMASK
 * 2 - [0,1,2] -> 0111(7)
 * 3 - [1,3] -> 1010(10)
 >> if we want to find the intersection of the two arrays(sorted) then  it is O(N)
 * INTERSECTION (&) 1100 & 0111 -> 0100 (2nd fruit is common) -> O(1)
 * UNION (|) 1100 | 0111 -> (ALL FRUITS ARE THERE) -> O(1)
 * There is limitation to it ->
 * Us. INT -> 32 BITS (Fruties <= 32)
 * Us. LONG LONG -> 64 BITS (Fruties <= 32)
 *

*/
void printBinary(int num) {
    for (int i = 32; i >= 0;--i) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

/*
Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.
*/
int main() {
    int n;
    cin >> n;
    vector<int> masks(n,0);
    for (int i = 0; i < n; i++) {
        int num_workers;
        cin >> num_workers;
        int mask = 0;
        for (int i = 0; i < num_workers; i++) {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << masks[i] << endl;
    //     printBinary(masks[i]);
    // }
    // O(N^2 * 30)
    int max_days = 0,personi = -1 ,personj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int intersection = (masks[i] & masks[j]);
            int common_days = __builtin_popcount(intersection);
            if (max_days < common_days) {
                personi = i;
                personj = j;
            }
            max_days = max(max_days, common_days);
            // cout << i << " " << j << " " << common_days << endl;
        }
    }
    cout << personi << " " << personj << " " << max_days;
    return 0;
}