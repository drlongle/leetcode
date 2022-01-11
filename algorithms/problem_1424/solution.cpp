/*
1424. Diagonal Traverse II
Medium

Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.

Example 1:
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

Example 2:
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

Example 3:
Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]

Example 4:
Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
There at most 10^5 elements in nums.
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

    struct Entry {
        Entry(int ai, int aj): i(ai), j(aj) {}
        int i, j;
        bool operator<(const Entry& other) {
            int rank = i + j, other_rank = other.i + other.j;
            return (rank < other_rank || (rank == other_rank && i > other.i));
        }
    };
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<Entry> entries;
        int m = nums.size();
        for (int i = 0; i < m; ++i) {
            int n = nums[i].size();
            for (int j = 0; j < n; ++j)
                entries.emplace_back(i, j);
        }
        sort(begin(entries), end(entries));
        vector<int> res;

        for (auto& entry: entries) {
            res.push_back(nums[entry.i][entry.j]);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums;
    vector<int> res;

    // Output: {1,4,2,7,5,3,8,6,9}
    nums = {{1,2,3},{4,5,6},{7,8,9}};
    res = sol.findDiagonalOrder(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16}
    nums = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    res = sol.findDiagonalOrder(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,4,2,5,3,8,6,9,7,10,11}
    nums = {{1,2,3},{4},{5,6,7},{8},{9,10,11}};
    res = sol.findDiagonalOrder(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,2,3,4,5,6}
    nums = {{1,2,3,4,5,6}};
    res = sol.findDiagonalOrder(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Expected: [14,13,12,11,14,19,13,15,16,1,8,9,11]
    nums = {{14,12,19,16,9},{13,14,15,8,11},{11,13,1}};
    res = sol.findDiagonalOrder(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
