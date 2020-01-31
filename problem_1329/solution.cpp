/*
1329. Sort the Matrix Diagonally
Medium

Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.

Example 1:
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
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
    void sortArray(vector<vector<int>>& nums, int x, int y) {
        int idx = 0;
        for (int i = x, j = y; i < m && j < n; ++i, ++j, ++idx)
            temp[idx] = nums[i][j];
        sort(begin(temp), begin(temp) + idx);
        
        idx = 0;
        for (int i = x, j = y; i < m && j < n; ++i, ++j, ++idx)
            nums[i][j] = temp[idx];
    }
    
    int m, n;
    vector<int> temp;
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& nums) {
        m = nums.size();
        n = nums[0].size();
        temp.resize(max(m, n));
        for (int i = 0; i < n; ++i)
            sortArray(nums, 0, i);
        for (int i = 1; i < m; ++i)
            sortArray(nums, i, 0);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums;

    // Output: {{1,1,1,1},{1,2,2,2},{1,2,3,3}}
    nums = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};

    auto res = sol.diagonalSort(nums);
    for (auto& row: res) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
