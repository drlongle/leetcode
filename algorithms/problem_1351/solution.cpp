/*
Easy

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:
Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:
Input: grid = [[-1]]
Output: 1

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    int find_negatives(const vector<int>& arr, int begin, int end) {
        int res = end+1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (arr[mid] < 0) {
                res = mid;
                end = mid - 1;
            } else
                begin = mid + 1;
        }

        return res;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        int index = 0;
        for (int i = m-1; i >= 0; --i) {
            index = find_negatives(grid[i], index, n-1);
            cnt += n - index;
        }
        
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: 8
    grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    // Output: 0
    //grid = {{3,2},{1,0}};

    // Output: 3
    //grid = {{1,-1},{-1,-1}};

    // Output: 1
    //grid = {{-1}};

    cout << sol.countNegatives(grid) << endl;
    
    return 0;
}
