/*
1762. Buildings With an Ocean View
Medium

There are n buildings in a line. You are given an integer array heights of size n that
represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can
see the ocean without obstructions. Formally, a building has an ocean view if all the buildings
to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Example 1:
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

Example 2:
Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.

Example 3:
Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.

Example 4:
Input: heights = [2,2,2,2]
Output: [3]
Explanation: Buildings cannot see the ocean if there are buildings of the same height to its right.

Constraints:
1 <= heights.length <= 10^5
1 <= heights[i] <= 10^9
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
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        for (int i = heights.size()-1, maxh = 0; i >= 0; --i) {
            if (heights[i] > maxh) {
                res.push_back(i);
                maxh = heights[i];
            }
        }
        sort(begin(res), end(res));

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> heights;

    // Output: {0,2,3}
    heights = {4,2,3,1};
    heights = sol.findBuildings(heights);
    copy(begin(heights), end(heights), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {0,1,2,3}
    heights = {4,3,2,1};
    heights = sol.findBuildings(heights);
    copy(begin(heights), end(heights), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {3}
    heights = {1,3,2,4};
    heights = sol.findBuildings(heights);
    copy(begin(heights), end(heights), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {3}
    heights = {2,2,2,2};
    heights = sol.findBuildings(heights);
    copy(begin(heights), end(heights), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
