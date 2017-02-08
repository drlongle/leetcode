/*
84. Largest Rectangle in Histogram
Total Accepted: 54043 Total Submissions: 228387 Difficulty: Hard

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram. 
For example,
Given heights = [2,1,5,6,2,3],
return 10.

Link:
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = static_cast<int>(heights.size());
        vector<int> height_index;
        vector<int> left_bounds, right_bounds(size);
        for (int i = 0; i < size; ++i)
        {
            while (height_index.size())
                if (heights[height_index.back()] >= heights[i])
                    height_index.pop_back();
                else
                    break;
            left_bounds.emplace_back(
                height_index.empty() ? 0 : height_index.back()+1);
            height_index.emplace_back(i);
        }
        height_index.clear();

        for (int i = size-1; i >= 0; --i)
        {
            while (height_index.size())
                if (heights[height_index.back()] >= heights[i])
                    height_index.pop_back();
                else
                    break;
            right_bounds[i] = height_index.empty() ? size : height_index.back();
            height_index.emplace_back(i);
        }

        int area, result = 0;
        for (int i = 0; i < size; ++i) {
            area = (right_bounds[i] == left_bounds[i]) ? heights[i] :
                (right_bounds[i] - left_bounds[i]) * heights[i];
            if (area > result)
                result = area;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    input = {2,1,5,6,2,3};

    int result = sol.largestRectangleArea(input);
    cout << "Result: " << result << endl;
    return 0;
}
