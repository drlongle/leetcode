/*
939. Minimum Area Rectangle
Medium

Given a set of points in the xy-plane, determine the minimum area of a rectangle
formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:
Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:
Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2

Note:
1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
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

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {

        int res = numeric_limits<int>::max();
        map<int, vector<int>> lines;
        for (auto& point: points) {
            int x = point[0], y = point[1];
            lines[x].emplace_back(y);

        }
        for (auto& line: lines) {
            sort(begin(line.second), end(line.second));
        }

        for (auto it = lines.begin(); it != lines.end(); ++it) {
            auto& p = it->second;
            int n = p.size();
            if (n == 1)
                continue;
            for (int i = 0; i < n; ++i) {
                int y1 = p[i];
                for (int j = i+1; j < n; ++j) {
                    int y2 = p[j];
                    for (auto it2 = next(it); it2 != lines.end(); ++it2) {
                        int area = (y2-y1)*(it2->first - it->first);
                        if (area > res)
                            continue;
                        if (binary_search(it2->second.begin(), it2->second.end(), y1)
                            && binary_search(it2->second.begin(), it2->second.end(), y2))
                            res = area;
                    }
                }
            }
        }

        return res == numeric_limits<int>::max() ? 0 : res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points;

    // Output: 4
    points = {{1,1},{1,3},{3,1},{3,3},{2,2}};
    cout << sol.minAreaRect(points) << endl;

    // Output: 2
    points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    cout << sol.minAreaRect(points) << endl;

    return 0;
}
