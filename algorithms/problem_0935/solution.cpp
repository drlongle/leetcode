/*
935. Knight Dialer
Medium

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

Example 1:
Input: 1
Output: 10

Example 2:
Input: 2
Output: 20

Example 3:
Input: 3
Output: 46

Note:
1 <= N <= 5000
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
    vector<vector<int>> neighs = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    static constexpr int mod_const = 1000000007;
    
    int knightDialer(int N) {
        vector<int> curr(10, 1), next(10);;
        for (int i = 2; i <= N; ++i) {
            for (int num = 0; num <= 9; ++num) {
                int sum = 0;
                for (auto neigh: neighs[num]) {
                    sum = (sum + curr[neigh]) % mod_const;
                }
                next[num] = sum;
            }
            swap(curr, next);
        }
        int sum = 0;
        for (size_t i = 0; i <= 9; ++i)
            sum = (sum + curr[i]) % mod_const;
        return sum;
    }
};

int main() {
    Solution sol;
    for (int n = 1; n <= 10; ++n)
        cout << n << " -> " << sol.knightDialer(n) << endl;
    return 0;
}
