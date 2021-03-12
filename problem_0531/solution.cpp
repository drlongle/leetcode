/*
531. Lonely Pixel I
Medium

Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.

A black lonely pixel is a character 'B' that located at a specific position where
the same row and same column don't have any other black pixels.

Example 1:
Input: picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
Output: 3
Explanation: All the three 'B's are black lonely pixels.

Example 2:
Input: picture = [["B","B","B"],["B","B","B"],["B","B","B"]]
Output: 0

Constraints:
m == picture.length
n == picture[i].length
1 <= m, n <= 500
picture[i][j] is 'W' or 'B'.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size ();
        vector<int> row(m, 0), col(n,0);
        for (int i = 0; i < m; ++i)
            row[i] = count(grid[i].begin(), grid[i].end(), 'B');

        for (int j = 0; j < n; ++j) {
            for (int i = 0;i < m; ++i)
                col[j] += grid[i][j] == 'B';
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){
                res += grid[i][j] =='B' && row[i]==1&&col[j] == 1;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
