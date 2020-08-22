/*
497. Random Point in Non-overlapping Rectangles
Medium

Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and
uniformly picks an integer point in the space covered by the rectangles.

Note:
An integer point is a point that has integer coordinates.
A point on the perimeter of a rectangle is included in the space covered by the rectangles.
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner,
and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.

Example 1:
Input:
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output:
[null,[4,1],[4,1],[3,3]]

Example 2:
Input:
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output:
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the
array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.
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
    Solution(vector<vector<int>>& r): rects(r), generator(rd()) {
        for (auto& rect: rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            int start = intervals.empty() ? 0 : intervals.back().second + 1;
            intervals.emplace_back(start, start + area);
        }
    }

    vector<pair<int, int>> intervals;

    int get_index() {
        std::uniform_int_distribution<int> dist1(0, intervals.back().second);
        int value = dist1(generator);
        int lo = 0, hi = intervals.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            auto& interval = intervals[mid];
            if (interval.first <= value && value <= interval.second)
                return mid;
            if (value < interval.first)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }

    vector<int> pick() {
        int index = get_index();
        auto& r = rects[index];
        std::uniform_int_distribution<int> dist2(r[0], r[2]);
        std::uniform_int_distribution<int> dist3(r[1], r[3]);
        int x = dist2(generator), y = dist3(generator);

        return {x, y};
    }

    vector<vector<int>> rects;
    std::random_device rd;
    std::mt19937 generator;
};

int main() {
    vector<vector<int>> rects;

    rects = {
            {82918473, -57180867, 82918476, -57180863},
            {83793579, 18088559, 83793580, 18088560},
            {66574245, 26243152, 66574246, 26243153},
            {72983930, 11921716, 72983934, 11921720}
    };
    Solution sol(rects);

    for (int i = 0; i < 10; ++i) {
        sol.pick();
    }

    return 0;
}
