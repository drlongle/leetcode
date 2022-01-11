/*
15. 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
    Elements in a triplet (a,b,c) must be in non-descending order (i.e., a <= b <= c).
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},
    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Input: [0,0,0,0]
Expected: [[0,0,0]]

[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
Expected: [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]] 

Input: [0,0]
Expected: [] 

Input: [-2,0,1,1,2]
Expected: [[-2,0,2],[-2,1,1]] 
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
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        set<vector<int>> temp;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int s_size = static_cast<int>(nums.size());
        int begin = 0, end = s_size -1;

        while (begin < end) {
            if (nums[begin]*nums[end] > 0)
                break;
            int first = begin, last = end;
            int index = findElement(nums, first, last);
            if (index >= 0)
                addResult(ret, nums, first, index, last);

            for (first = begin+1; first < end; ++first) {
                if (nums[first] == nums[first-1])
                    continue;
                index = findElement(nums, first, end);
                if (index >= 0)
                    addResult(ret, nums, first, index, end);
            }

            for (last = end-1; last > begin; --last) {
                if (nums[last] == nums[last+1])
                    continue;
                index = findElement(nums, begin, last);
                if (index >= 0)
                    addResult(ret, nums, begin, index, last);
            }

            int skip = nums[begin];
            ++begin;
            while(begin < end && nums[begin] == skip)
                ++begin;

            skip = nums[end];
            --end;
            while(begin < end && nums[end] == skip)
                --end;
        }

        return ret;
    }

    void addResult(vector<vector<int>>& ret, vector<int>& nums, int i1,
        int i2, int i3) {
        vector<int> subres;
        subres.push_back(nums[i1]);
        subres.push_back(nums[i2]);
        subres.push_back(nums[i3]);
        ret.emplace_back(subres);
    }

    int findElement(vector<int>& nums, int begin, int end) {
        int first = begin, last = end;
        int sum = -(nums[first] + nums[last]);
        int middle, index = -1;
        while (first <= last) {
            middle = (first + last) >> 1;
            if (nums[middle] == sum) {
                if (middle != begin && middle != end) {
                    index = middle;
                    break;
                }
                if (middle == end)
                    last = middle-1;
                else if (middle == begin)
                    first = middle+1;
            } else if (nums[middle] > sum)
                last = middle-1;
            else
                first = middle+1;
        }
        return index;
    }
};

int main()
{
    Solution sol;
    vector<int> input{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> ret = sol.threeSum(input);
    for (const auto& v: ret) {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}

