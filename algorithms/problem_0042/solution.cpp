/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
*/

#include <algorithm>
#include <cassert>
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
    enum Direction
    {
        DOWN = 0,
        UP = 1
    };

    int compute_water(vector<int>& height, int index1, int index2)
    {
        int result = 0;
        int h = min(height[index1], height[index2]);
        for (int i = index2-1; i > index1; --i)
            if (h > height[i]) result += h - height[i];
            else if (height[i] > height[index2]) break;

        return result;
    }

    int trap(vector<int>& height)
    {
        int result = 0;
        int size = static_cast<int>(height.size());
        vector<int> tops;
        map<pair<int,int>, int> cache;
        if (size < 3)
            return 0;

        Direction direct = (height[1] > height[0]) ? UP : DOWN;
        if (direct == DOWN) tops.push_back(0);
        for (int i = 2; i < size; ++i)
        {
            if (height[i] < height[i-1] && direct == UP)
            {
                direct = DOWN;
                if (tops.size() > 0)
                {
                    int prev_up = tops.size()-1;
                    for ( ; prev_up >= 0; --prev_up)
                    {
                        if (height[tops[prev_up]] >= height[i-1]) break;
                    }
                    pair<int, int> newpair(tops[max(prev_up, 0)], i-1);
                    int water = compute_water(height,tops[max(prev_up, 0)],i-1);
                    result += water;
                    map<pair<int,int>,int>::iterator it = cache.begin();
                    while (it != cache.end())
                    {
                        if (it->first.first >= newpair.first &&
                            it->first.second <= newpair.second)
                        {
                            result -= it->second;
                            it = cache.erase(it);
                        }
                        else
                            ++it;
                    } 
                    cache[newpair] = water;
                }
                while (tops.size() > 0)
                {
                    if (height[tops.back()] < height[i-1]) tops.pop_back();
                    else break;
                }

                tops.push_back(i-1);
            }
            else
            {
                if (height[i] > height[i-1] && direct == DOWN)
                    direct = UP;
                if (i == size -1 && direct == UP)
                {
                    if (tops.size() > 0)
                    {
                        int prev_up = tops.size()-1;
                        for ( ; prev_up >= 0; --prev_up)
                            if (height[tops[prev_up]] >= height[i])
                                break;
                        result += compute_water(height, tops[max(0,prev_up)], i);
                        pair<int, int> newpair(tops[max(prev_up, 0)], i);
                        for (const auto& c: cache)
                        {
                            if (c.first.first >= newpair.first &&
                                c.first.second <= newpair.second)
                                result -= c.second;
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    // Expected: 83
    input = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};

    cout << "Result: " << sol.trap(input);
    return 0;
}
