/*
62. Unique Paths
Total Accepted: 91247 Total Submissions: 248005 Difficulty: Medium

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below). The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below). How many possible unique paths are there? Note: m and n will be at most 100.
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
    int uniquePaths(int m, int n) ;
};

int Solution::uniquePaths(int m, int n)
{
    vector<vector<int>> nums = vector<vector<int>>(m, vector<int>(n));
    nums[m-1][n-1] = 1;

    for (int i = m-1; i >= 0; --i)
        for (int j = n-1; j >= 0; --j)
        {
            if (i != m-1 || j != n-1)
                nums[i][j] = (i < m-1 ? nums[i+1][j] : 0) +
                    (j < n-1 ? nums[i][j+1] : 0);
        }
    return nums[0][0];
}

int main()
{
    Solution sol;
    int m,n;

    m = 1, n = 2;
    cout << "Result: " << sol.uniquePaths(m,n) << endl;

    return 0;
}

