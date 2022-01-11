/*
1388. Pizza With 3n Slices
Hard

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick next slice in anti clockwise direction of your pick. 
Your friend Bob will pick next slice in clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Sizes of Pizza slices is represented by circular array slices in clockwise direction.

Return the maximum possible sum of slice sizes which you can have.

Example 1:
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Example 2:
Input: slices = [8,9,8,6,1,1]
Output: 16
Output: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.

Example 3:
Input: slices = [4,1,2,5,8,3,1,9,7]
Output: 21

Example 4:
Input: slices = [3,1,2]
Output: 3

Constraints:
1 <= slices.length <= 500
slices.length % 3 == 0
1 <= slices[i] <= 1000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int res = 0, sz = slices.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            dp[i][(i+2) % sz] = slices[(i+1) % sz];
            res = max(res, slices[(i+1) % sz]);
        }
        for (int len = 6; len <= sz; len += 3) {
            for (int i = 0; i < sz; ++i) {
                int begin = i, end = (begin + len -4) % sz;
                int temp = dp[begin][end];

                dp[begin][(end+3)%sz] = max(dp[begin][(end+3)%sz], temp + slices[(end+2)%sz]);
                dp[(begin+sz-1)%sz][(end+2)%sz] = max(dp[(begin+sz-1)%sz][(end+2)%sz], temp +slices[(end+1)%sz]);
                dp[(begin+sz-2)%sz][(end+1)%sz] = max(dp[(begin+sz-2)%sz][(end+1)%sz], temp +slices[(begin+sz-1)%sz]);
                for (int sublen = 3; sublen < len; sublen += 3) {
                    int new_end = (begin+len-1)%sz;
                    dp[begin][new_end] = max(dp[begin][new_end], dp[begin][(begin+sublen-1)%sz] + slices[(begin+sublen) % sz] + dp[(begin+sublen+1) % sz][(begin+len-2) % sz]);
                    dp[begin][new_end] = max(dp[begin][new_end], dp[begin][(begin+sublen-1)%sz] + dp[(begin+sublen) % sz][new_end]);
                    res = max(res, dp[begin][new_end]);
                }
                res = max({res, dp[begin][(end+3)%sz], dp[(begin+sz-1)%sz][(end+2)%sz], dp[(begin+sz-2)%sz][(end+1)%sz]});
                if (len == sz) {
                    res = max(res, temp + max({slices[(end+1)%sz], slices[(begin+sz-1)%sz], slices[(begin+sz-2)%sz]}));
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> slices;

    // Output: 10
    slices = {1,2,3,4,5,6};
    cout << sol.maxSizeSlices(slices) << endl;
    
    // Output: 16
    slices = {8,9,8,6,1,1};
    cout << sol.maxSizeSlices(slices) << endl;
    
    // Output: 21
    slices = {4,1,2,5,8,3,1,9,7};
    cout << sol.maxSizeSlices(slices) << endl;
    
    // Output: 3
    slices = {3,1,2};
    cout << sol.maxSizeSlices(slices) << endl;

    // Expected: 36
    slices = {3,10,3,2,10,7,6,5,5,6,10,7};
    cout << sol.maxSizeSlices(slices) << endl;

    // Expected: 40
    slices = {10,5,6,2,5,1,9,3,3,6,1,5,9,4,2};
    cout << sol.maxSizeSlices(slices) << endl;

    // Expected: 30
    slices = {10,9,1,10,8,5,10,2,2};
    cout << sol.maxSizeSlices(slices) << endl;

    // Expected: 91
    slices = {10,5,1,9,6,8,9,2,5,6,6,6,1,8,2,3,10,3,6,10,8,1,2,4,5,4,3,2,9,5,7,9,8};
    cout << sol.maxSizeSlices(slices) << endl;

    // Exüected: 153
    slices = {2,4,3,1,5,9,4,4,5,6,5,7,6,3,10,6,8,8,8,3,5,5,8,1,8,2,6,7,2,1,3,4,7,10,8,7,9,5,1,1,9,10,3,10,5,10,5,2,4,6,6,1,9,4,8,2,1};
    cout << sol.maxSizeSlices(slices) << endl;
    
    return 0;
}
