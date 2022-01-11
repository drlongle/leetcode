/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. 

Input: [1,1]
Expected: 1

Input: [1,2,1]
Expected: 2
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
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
    int maxArea(vector<int>& height)
    {
        int h_size = static_cast<int>(height.size());
        int maxarea = 0;
        multimap<int, int> scratch;
        multimap<int, int>::const_iterator it;
        for (int i = 0; i < h_size; ++i) {
            it = scratch.lower_bound(height[i]);
            if (it == scratch.end()) {
                scratch.emplace(height[i], i);
                continue;
            }
            if (height[i]*i < maxarea) continue;
            for ( ; it != scratch.end(); ++it) {
                int temp = min(height[i], it->first) * (i - it->second);
                maxarea = max(temp, maxarea);
            }
        }

        scratch.clear();
        for (int i = h_size-1; i >= 0; --i) {
            it = scratch.lower_bound(height[i]);
            if (it == scratch.end()) {
                scratch.emplace(height[i], i);
                continue;
            }
            if (height[i]*(h_size-i-1) < maxarea) continue;
            for ( ; it != scratch.end(); ++it) {
                int temp = min(height[i], it->first) * (it->second-i);
                maxarea = max(temp, maxarea);
            }
        }
 
        return maxarea;
    }
};

int main()
{
    Solution solution;
    vector<int> height{1,2,4,3}; //expected: 4
    cout << solution.maxArea(height) << endl;

    return 0;
}

