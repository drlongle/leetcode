/*
63. Unique Paths II
Total Accepted: 68651 Total Submissions: 231779 Difficulty: Medium

Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2. Note: m and n will be at most 100.
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) ;
};

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    if (!m) return 0;
    int n = obstacleGrid[0].size();
    if (!n) return 0;
    if (obstacleGrid[m-1][n-1]) return 0;

    vector<vector<long long>> nums(m, vector<long long>(n, 0));

    nums[m-1][n-1] = 1;

    for (int i = m-1; i >= 0; --i)
        for (int j = n-1; j >= 0; --j)
        {
            if ((i != m-1 || j != n-1) && !obstacleGrid[i][j])
            nums[i][j] = (i < m-1 ? nums[i+1][j] : 0) +
                (j < n-1 ? nums[i][j+1] : 0);
        }
    return nums[0][0];
}

int main()
{
    Solution sol;
    vector<vector<int>> obstacleGrid;
    obstacleGrid = { {0,0,0}, {0,1,0}, {0,0,0} };
    cout << "Result: " << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}

