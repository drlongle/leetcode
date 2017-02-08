/*
16. 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Input: [1,1,-1,-1,3]
Target: -1
Expected: -1 
 */

#include <algorithm>
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
    Solution() : m_diff(numeric_limits<int>::max()), m_sum(0) {}

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s_size = static_cast<int>(nums.size());
        int begin = 0, end = s_size -1;
        int index;
        int first, last, subsum;
        while (begin + 1< end) {
            first = begin;
            last = end;
            subsum = nums[first] + nums[last];
            index = findClosest(nums, target-subsum, first, last);
            if (index >= 0)
                updateResult(nums, target, first, index, last);

            for (first = begin+1; first +1 < end; ++first) {
                if (nums[first] == nums[first-1]) continue;
                subsum = nums[first] + nums[end];
                index = findClosest(nums, target-subsum, first, end);
                if (index >= 0)
                    updateResult(nums, target, first, index, end);
            }

            for (last = end-1; last > begin+1; --last) {
                if (nums[last] == nums[last+1]) continue;
                subsum = nums[begin] + nums[last];
                index = findClosest(nums, target-subsum, begin, last);
                if (index >= 0)
                    updateResult(nums, target, begin, index, last);
            }

            if (m_sum == target)
                break;

            ++begin;
            --end;
        }

        return m_sum; 
    }

    int findClosest(vector<int>& nums, int target, int begin, int end) {
        int middle = -1;
        int first = begin+1, last = end-1;
        while (first <= last) {
            middle = (first + last) >> 1;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] > target)
                last = middle -1;
            else
                first = middle +1;
        }

        return middle;
    }

    void updateResult(vector<int>& nums, int target, int id1, int id2, int id3)
    {
        int sum = nums[id1] + nums[id2] + nums[id3];
        int diff = abs(target - sum);
        if (diff < m_diff) {
            m_diff = diff;
            m_sum = sum;
        }
    }

private:
    int m_diff;
    int m_sum;
};

int main()
{
    Solution sol;
    vector<int> input{-1, 2, 1, -4};
    int target = 1;
    cout << "Solution: " << sol.threeSumClosest(input, target) << endl;

    return 0;
}
