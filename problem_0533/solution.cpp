/*
533. Lonely Pixel II
Medium

Given an m x n picture consisting of black 'B' and white 'W' pixels and an integer target, return the number of black lonely pixels.

A black lonely pixel is a character 'B' that located at a specific position (r, c) where:
Row r and column c both contain exactly target black pixels.
For all rows that have a black pixel at column c, they should be exactly the same as row r.

Example 1:
Input: picture = [["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","W","B","W","B","W"]], target = 3
Output: 6
Explanation: All the green 'B' are the black pixels we need (all 'B's at column 1 and 3).
Take 'B' at row r = 0 and column c = 1 as an example:
 - Rule 1, row r = 0 and column c = 1 both have exactly target = 3 black pixels.
 - Rule 2, the rows have black pixel at column c = 1 are row 0, row 1 and row 2. They are exactly the same as row r = 0.

Example 2:
Input: picture = [["W","W","B"],["W","W","B"],["W","W","B"]], target = 1
Output: 0

Constraints:
m == picture.length
n == picture[i].length
1 <= m, n <= 200
picture[i][j] is 'W' or 'B'.
1 <= target <= min(m, n)
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    vector<vector<bool>> match;
    vector<int> rows, cols;
    int m, n;

    bool compare(vector<vector<char>>& picture, int i, int j) {
        if (rows[i] != rows[j])
            return false;
        for (int k = 0; k < n; ++k)
            if(picture[i][k] != picture[j][k])
                return false;
            return true;
    }

    int findBlackPixel(vector<vector<char>>& picture, int target) {
        m = picture.size(), n = picture[0].size();
        int res = 0;
        match.resize(m, vector<bool>(m, false));
        rows.resize(m, 0), cols.resize(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += (picture[i][j] == 'B');
                cols[j] += (picture[i][j] == 'B');
            }
        }

        for (int i = 0; i < m ; ++i) {
            for (int j = i+1; j < m; ++j) {
                match[i][j] = match[j][i] = compare(picture, i, j);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (cols[j] != target)
                continue;
            int i = 0, cnt = 0;
            while (picture[i][j] != 'B')
                ++i;
            if (rows[i] != target)
                continue;
            ++cnt;
            for (int k = i + 1; cnt && k < m; ++k) {
                if (picture[k][j] != 'B')
                    continue;
                if (match[i][k])
                    ++cnt;
                else
                    cnt = 0;
            }
            res += cnt;
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
