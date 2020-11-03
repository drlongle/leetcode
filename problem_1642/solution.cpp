/*
1642. Furthest Building You Can Reach
Medium

You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

Example 1:
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.

Example 2:
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7

Example 3:
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3

Constraints:
1 <= heights.length <= 105
1 <= heights[i] <= 106
0 <= bricks <= 109
0 <= ladders <= heights.length
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    bool reach(vector<int>& heights, int bricks, int ladders, int index) {
        vector<int> obstacles;
        for (int i = 0; i < index; ++i) {
            int dh = heights[i+1] - heights[i];
            if (dh > 0)
                obstacles.emplace_back(dh);
        }
        sort(begin(obstacles), end(obstacles));
        int i = 0, sz = obstacles.size();
        for (; i < sz && bricks >= obstacles[i]; ++i) {
            bricks -= obstacles[i];
        }

        return ladders + i >= sz;
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int lo = 0, hi = heights.size() - 1, res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (reach(heights, bricks, ladders, mid)) {
                res = mid;
                lo = mid + 1;
            } else
                hi = mid-1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> heights;
    int ladders, bricks;

    // Output: 4
    heights = {4,2,7,6,9,14,12}, bricks = 5, ladders = 1;
    cout << sol.furthestBuilding(heights, bricks, ladders) << endl;

    // Output: 7
    heights = {4,12,2,7,3,18,20,3,19}, bricks = 10, ladders = 2;
    cout << sol.furthestBuilding(heights, bricks, ladders) << endl;

    // Output: 3
    heights = {14,3,19,3}, bricks = 17, ladders = 0;
    cout << sol.furthestBuilding(heights, bricks, ladders) << endl;

    return 0;
}
