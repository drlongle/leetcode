/*
356. Line Reflection
Medium

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points
symmetrically, in other words, answer whether or not if there exists a line that after reflecting all points
over the given line the set of the original points is the same that the reflected ones.

Note that there can be repeated points.

Follow up: Could you do better than O(n^2)?

Example 1:
Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.

Example 2:
Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.

Constraints:
n == points.length
1 <= n <= 10^4
-10^8 <= points[i][j] <= 10^8
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
    bool isReflected(vector<vector<int>>& points) {
        unordered_map <int,vector <int>> lines;
        for (auto& point: points) {
            lines[point[1]].push_back(point[0]);
        }

        set<double> nums;

        for (auto& [ignored, line]: lines) {
            sort(begin(line), end(line));
            line.erase(unique(begin(line),end(line)), end(line));
            int sz = line.size();
            double y = (sz & 1) ? line[sz / 2] : ((double) (line[0] + line.back())) / 2;
            nums.insert(y);
            if (nums.size() > 1)
                return false;
            for (int i = 0, j = sz - 1; i < j; ++i, --j){
                if (y - line[i] != line[j] - y)
                    return false;
            }

        }

        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
