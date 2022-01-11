/*
1893. Check if All the Integers in a Range Are Covered
Easy

You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi]
represents an inclusive interval between starti and endi.

Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges.
Return false otherwise.

An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.

Example 1:
Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
Output: true
Explanation: Every integer between 2 and 5 is covered:
- 2 is covered by the first range.
- 3 and 4 are covered by the second range.
- 5 is covered by the third range.

Example 2:
Input: ranges = [[1,10],[10,20]], left = 21, right = 21
Output: false
Explanation: 21 is not covered by any range.

Constraints:
1 <= ranges.length <= 50
1 <= starti <= endi <= 50
1 <= left <= right <= 50
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i <= right; ++i) {
            bool found = false;
            for (auto& range: ranges) {
                if (range[0] <= i && i <= range[1]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ranges;
    int left, right;

    // Output: true
    ranges = {{1,2},{3,4},{5,6}}, left = 2, right = 5;
    cout << sol.isCovered(ranges, left, right) << endl;

    // Output: false
    ranges = {{1,10},{10,20}}, left = 21, right = 21;
cout << sol.isCovered(ranges, left, right) << endl;


    return 0;
}
