/*
2028. Find Missing Observations
Medium

https://leetcode.com/problems/find-missing-observations/

You have observations of n + m 6-sided dice rolls with each face numbered from 1
to 6. n of the observations went missing, and you only have the observations of
m rolls. Fortunately, you have also calculated the average value of the n + m
rolls.

You are given an integer array rolls of length m where rolls[i] is the value of
the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the
average value of the n + m rolls is exactly mean. If there are multiple valid
answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.
Note that mean is an integer, so the sum of the n + m rolls should be divisible
by n + m.


Example 1:
Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

Example 2:
Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.

Example 3:
Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing
rolls are.

Constraints:
m == rolls.length
1 <= n, m <= 10^5
1 <= rolls[i], mean <= 6
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        vector<int> res;
        int m = rolls.size();
        long long sum =
            mean * (m + n) - std::accumulate(rolls.begin(), rolls.end(), 0);
        if (sum < n || sum > n * 6)
            return res;
        std::array<int, 6> dices{1, 2, 3, 4, 5, 6};
        while (n > 0) {
            for (int d : dices) {
                int n_sum = sum - d;
                if (n_sum < n - 1 || n_sum > 6 * (n - 1))
                    continue;
                sum = n_sum;
                res.push_back(d);
                --n;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> rolls, res;
    int mean, n;

    rolls = {3, 2, 4, 3}, mean = 4, n = 2;
    res = sol.missingRolls(rolls, mean, n);
    copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
    cout << endl;

    rolls = {1, 5, 6}, mean = 3, n = 4;
    res = sol.missingRolls(rolls, mean, n);
    copy(begin(res), end(res), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
