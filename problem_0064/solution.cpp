/*
64. Minimum Path Sum
Total Accepted: 73847 Total Submissions: 209120 Difficulty: Medium

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid);
};

int Solution::minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    if (!m) return 0;
    int n = grid[0].size();
    if (!n) return 0;

    vector<vector<int>> nums = vector<vector<int>>(m, vector<int>(n, 0));

    nums[m-1][n-1] = grid[m-1][n-1];

    for (int i = m-1; i >= 0; --i)
        for (int j = n-1; j >= 0; --j)
        {
            if (i == m-1 && j == n-1)
                continue;
            if (i == m-1)
                nums[i][j] = grid[i][j] + nums[i][j+1];
            else if (j == n-1)
                nums[i][j] = grid[i][j] + nums[i+1][j];
            else
                nums[i][j] = grid[i][j] + min(nums[i+1][j], nums[i][j+1]);
        }
    return nums[0][0];
}

int main()
{
    Solution sol;
    vector<vector<int>> grid;
    grid = { {0,0,0}, {0,1,0}, {0,0,0} };
    cout << "Result: " << sol.minPathSum(grid) << endl;

    return 0;
}

