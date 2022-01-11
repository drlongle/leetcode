/*
18. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
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
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int s_size = static_cast<int>(nums.size());
        int begin = 0, end = s_size -1;

        while (begin +2 < end)
        {
            if (accumulate(nums.begin()+begin, nums.begin()+begin+4, 0)> target)
                break;
            if (accumulate(nums.begin()+end-3, nums.begin()+end+1, 0) < target)
                break;

            int i1 = begin, i4 = end;
            for (int i2 = i1+1; i2 +1< i4; ++i2)
            {
                int subsum = nums[i1] + nums[i4] + nums[i2];
                int i3 = findElement(nums, i2, i4, target-subsum);
                if (i3 >= 0)
                    addResult(ret, nums, i1, i2, i3, i4);
            } 

            i4 = end;
            for (i1 = begin+1; i1+2 < i4; ++i1)
            {
                if (nums[i1] == nums[i1-1])
                    continue;
                for (int i2 = i1+1; i2 +1< i4; ++i2)
                {
                    int subsum = nums[i1] + nums[i4] + nums[i2];
                    int i3 = findElement(nums, i2, i4, target-subsum);
                    if (i3 >= 0)
                        addResult(ret, nums, i1, i2, i3, i4);
                }
            }

            i1 = begin;
            for (i4 = end-1; i4 > i1+2; --i4)
            {
                if (nums[i4] == nums[i4+1])
                    continue;
                for (int i2 = i1+1; i2 +1< i4; ++i2)
                {
                    int subsum = nums[i1] + nums[i4] + nums[i2];
                    int i3 = findElement(nums, i2, i4, target-subsum);
                    if (i3 >= 0)
                        addResult(ret, nums, i1, i2, i3, i4);
                }
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

        for (const auto& v: m_results)
            ret.emplace_back(v);

        return ret;
    }

    void addResult(vector<vector<int>>& ret, vector<int>& nums,
        int i1, int i2, int i3, int i4)
    {
        vector<int> subres;
        subres.push_back(nums[i1]);
        subres.push_back(nums[i2]);
        subres.push_back(nums[i3]);
        subres.push_back(nums[i4]);
        m_results.emplace(subres);
    }

    int findElement(vector<int>& nums, int begin, int end, int target)
    {
        int first = begin+1, last = end-1;
        int middle;
        while (first <= last)
        {
            middle = (first + last) >> 1;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target)
                last = middle-1;
            else
                first = middle+1;
        }
        return -1;
    }

private:
    set<vector<int> > m_results;
};

int main()
{
    Solution sol;
    vector<int> input {2,1,0,-1};
    int target = 2;

    vector<vector<int>> ret = sol.fourSum(input, target);
    for (const auto& v: ret) {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
