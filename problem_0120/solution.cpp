/*
120. Triangle
Total Accepted: 72719 Total Submissions: 237400 Difficulty: Medium

Given a triangle, find the minimum path sum from top to bottom. Each step you
may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is
the total number of rows in the triangle.  
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        for (int i = size-2; i >= 0; --i)
        {
            for (int j = 0; j < static_cast<int>(triangle[i].size()); ++j)
            {
                int temp = triangle[i+1][j];
                if (j < static_cast<int>(triangle[i+1].size())-1 &&
                    temp > triangle[i+1][j+1])
                    temp = triangle[i+1][j+1];
                triangle[i][j] += temp;
            }
        }
        return triangle[0][0];
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > triangle;
  
    // Expected: 11
    triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << "Result: " << sol.minimumTotal(triangle) << endl;

    return 0;
}

