/*
1039. Minimum Score Triangulation of Polygon
Medium

Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Example 1:
Input: [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:
Input: [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.

Example 3:
Input: [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

Note:
3 <= A.length <= 50
1 <= A[i] <= 100
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int compute(vector<int>& nums, int begin, int end) {
        if (begin + 2 == end) {
            auto res = nums[begin] * nums[begin+1] * nums[end];
            return res;
        }
        int res = dp[begin][end];
        if (res != numeric_limits<int>::max())
            return res;
        for (int i = begin+1; i != end; ++i) {
            auto curr = nums[begin] * nums[i] * nums[end];
            if (i != begin+1)
                curr += compute(nums, begin, i);
            if (end != i+1)
                curr += compute(nums, i, end);
            res = min(res, curr);
        }
        return dp[begin][end] = res;
    }
    
    int minScoreTriangulation(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n, numeric_limits<int>::max()));
        return compute(nums, 0, n-1);
    }
};

int main() {
    vector<int> nums;

    // Output: 6
    {
        Solution sol;
        nums = {1,2,3};
        cout << sol.minScoreTriangulation(nums) << endl;
    }
    
    // Output: 144
    {
        Solution sol;
        nums = {3,7,4,5};
        cout << sol.minScoreTriangulation(nums) << endl;
    }
    
    // Output: 13
    {
        Solution sol;
        nums = {1,3,1,4,1,5};
        cout << sol.minScoreTriangulation(nums) << endl;
    }
    
    return 0;
}
