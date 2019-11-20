/*
1259. Handshakes That Don't Cross
Hard

You are given an even number of people num_people that stand around a circle and each person
shakes hands with someone else, so that there are num_people / 2 handshakes total.
Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since this number could be very big, return the answer mod 10^9 + 7

Example 1:
Input: num_people = 2
Output: 1

Example 2:
Input: num_people = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].

Example 3:
Input: num_people = 6
Output: 5

Example 4:
Input: num_people = 8
Output: 14
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
    static constexpr int mod_const = 1000000007;

    int numberOfWays(int num) {
        dp.resize(1001);
        return countWays(num);
    }
    
    int countWays(int num) {
        if (num == 0 || num == 2)
            return 1;
        if (dp[num] > 0)
            return dp[num];
        int res = 0;
        for (int i = 1; i <= num - 1; i += 2) {
            long long a = i > 3 ? countWays(i-1) % mod_const : 1;
            long long b = num-i > 3 ? countWays(num-i-1) % mod_const : 1;
            res = (res + (a * b) % mod_const) % mod_const;
        }
        return dp[num] = res % mod_const;
    }

    vector<int> dp;
};

int main() {
    Solution sol;
    auto nums = {2, 4, 6, 8, 10, 140};

    for (auto num: nums)
        cout << num << " -> " << sol.numberOfWays(num) << endl;
    
    return 0;
}
