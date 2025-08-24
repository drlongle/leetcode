/*
2554. Maximum Number of Integers to Choose From a Range I
Medium

You are given an integer array banned and two integers n and maxSum. You are
choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.

Example 1:
Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6,
which did not exceed maxSum.

Example 2:
Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.

Example 3:
Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28,
which did not exceed maxSum.

Constraints:
1 <= banned.length <= 10^4
1 <= banned[i], n <= 10^4
1 <= maxSum <= 10^9
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> lookup(banned.begin(), banned.end());
        int count = 0;
        int sum = 0;
        for (int i = 1; i <= n && sum <= maxSum; i++) {
            if (lookup.count(i) == 0 && sum  + i <= maxSum) {
                ++count;
                sum += i;
            }
        }

        return count;
    }
};


int main() {
    Solution sol;
    vector<int> banned;
    int n, maxSum;

    banned = {1,6,5}, n = 5, maxSum = 6;
    cout << sol.maxCount(banned, n, maxSum) << endl;

    banned = {1,2,3,4,5,6,7}, n = 8, maxSum = 1;
    cout << sol.maxCount(banned, n, maxSum) << endl;

    banned = {11}, n = 7, maxSum = 50;
    cout << sol.maxCount(banned, n, maxSum) << endl;

    return 0;
}
