/*
2033. Minimum Operations to Make a Uni-Value Grid
Medium

You are given a 2D integer grid of size m x n and an integer x. In one
operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not
possible, return -1.

Example 1:
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following:
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Example 2:
Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.

Example 3:
Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10^5
1 <= m * n <= 10^5
1 <= x, grid[i][j] <= 10^4
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
    int count(unordered_map<int, int> &freq, int m, int x) {
        int count = 0;
        for (auto [k, v] : freq) {
            count += v * (abs(m - k) / x);
        }
        return count;
    }

    int minOperations(vector<vector<int>> &grid, int x) {
        unordered_map<int, int> freq;
        int m = numeric_limits<int>::max(), M = numeric_limits<int>::min();
        int sum = 0;
        for (auto &row : grid) {
            for (int n : row) {
                m = min(m, n);
                M = max(M, n);
                sum += n;
                ++freq[n];
            }
        }

        for (auto [k, v] : freq) {
            if ((k - m) % x != 0)
                return -1;
        }

        int avg = sum / (grid.size() * grid[0].size());
        int p = m + ((avg - m) / x) * x;
        int cnt = count(freq, p, x);
        constexpr int N = 20;

        for (int i = 1; i < N; ++i) {
            int p = m + ((avg - m) / x + i) * x;
            cnt = min(cnt, count(freq, p, x));
        }

        for (int i = 1; i < N; ++i) {
            int p = m + ((avg - m) / x - i) * x;
            if (p < 0)
                break;
            cnt = min(cnt, count(freq, p, x));
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    int x;
    vector<vector<int>> grid;

    grid = {{2, 4}, {6, 8}}, x = 2;
    cout << sol.minOperations(grid, x) << endl;

    grid = {{1, 5}, {2, 3}}, x = 1;
    cout << sol.minOperations(grid, x) << endl;

    grid = {{1, 2}, {3, 4}}, x = 2;
    cout << sol.minOperations(grid, x) << endl;

    grid = {{3, 1, 2}}, x = 2;
    cout << sol.minOperations(grid, x) << endl;

    grid = {{529, 529, 989}, {989, 529, 345}, {989, 805, 69}}, x = 92;
    cout << sol.minOperations(grid, x) << endl;

    return 0;
}
