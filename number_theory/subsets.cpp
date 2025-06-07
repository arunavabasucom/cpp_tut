/**
 * (8)
 * SUBSET GENERATE USING BIT MASKING
 */
#include <io_setup.h>
#include <bits/stdc++.h>
using namespace std;
/**
 * [2,3,7,8,9] 00000
 * [3,8] -> 01010
 * N sized has 2^N subsets ([2,4,5] -> _ _ _ in this position we have two desition that if we want to take it or not-> [],[2],[4],[5],[2,4],[4,5],[5,2],[2,4,5])
 * n - 2^N
 * 0 - 2^N-1
 * 0 - 000 - [] 
 * 1 - 001 - [2]
 * 2 - 010 - [4]
 * 3 - 011 - [2,4]
 * 4 - 100 - [5]
 * 5 - 101 - [5,2]
 * 6 - 110 - [5,4]
 * 7 - 111 - [2,5,4]
 */

vector<vector<int>> subsets(vector<int>& nums) {
    // O(n*(2^N))
    vector<vector<int>> res;
    int N = nums.size();
    int SC = (1 << N); // 2^N    
    for (int mask = 0; mask < SC; ++mask) {
        vector<int> subset;
        // check which bits are set in the mask 0,1,2...N
        for (int i = 0; i < N; ++i) {
            if ((mask & (1 << i)) != 0)
                subset.push_back(nums[i]);
        }
        res.push_back(subset);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    auto all_subsets = subsets(v);
    for (auto subset : all_subsets) {
        for (int ele : subset) {
            cout << ele << " ";
        }
        cout << endl;
    }
}