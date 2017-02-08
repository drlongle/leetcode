/*
410. Split Array Largest Sum

    Total Accepted: 186
    Total Submissions: 1466
    Difficulty: Medium

Given an array which consists of non-negative integers and an integer m, you
can split the array into m non-empty continuous subarrays. Write an algorithm
to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 <= m <= length(nums) <= 14,000.

Examples:

Input:
nums = [1,2,3,4,5]
m = 2

Output:
9

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5],
where the largest sum among the two subarrays is only 9.

 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

int sum(int start, int end)
{
    int diff = end - start;
    int result = start*(diff+1);
    result += (diff*(diff+1) >> 1);
    return result;
}

class My_interval
{
public:
    My_interval(int s, int e) : start(s), end(e) { }

    int split()
    {
        int sum1 = start;
        int sum2 = sum(start+1, end);
        int min_max_sum = max(sum1, sum2);
        int result = start;
        int index = start+1;
        while (sum1 <= sum2 && index <= end)
        {
            sum1 += index;
            sum2 -= index;
            int temp = max(sum1, sum2);
            if (temp < min_max_sum)
            {
                min_max_sum = temp;
                result = index;
            }
            ++index;
        }

        return result;
    }

    int start, end;
};

class Compare
{
public:
    bool operator()(const My_interval& i1, const My_interval& i2) const
    {
        return sum(i1.start, i1.end) < sum(i2.start, i2.end);
    }
};

class Solution {
public:

    int splitArray(vector<int>& nums, int m) {
        sort(nums.begin(), nums.end());
        vector<My_interval> My_intervals;
        int prev = nums[0];
        int start = prev;
        int curr = prev;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            curr = nums[i];
            if (curr > prev + 1 && start > prev)
            {
                My_intervals.emplace_back(My_interval(start,prev));
                start = curr;
            }
            prev = curr;
        }
        My_intervals.emplace_back(My_interval(start,curr));

        Compare compare;
        while (static_cast<int>(My_intervals.size()) < m)
        {
            sort(My_intervals.begin(), My_intervals.end(), compare);
            My_interval back = My_intervals.back();
            My_intervals.pop_back();
            int index = back.split();
            My_intervals.emplace_back(My_interval(back.start, index));
            My_intervals.emplace_back(My_interval(index+1,back.end));
        }
        sort(My_intervals.begin(), My_intervals.end(), compare);
        for (const auto& i: My_intervals)
            cout << i.start << " --> " << i.end << endl;
        My_interval back = My_intervals.back();
        int result = sum(back.start, back.end);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int m;

    nums = {1,2,3,4,5};
    m = 2;

    nums = {1,2147483646};
    m = 1;

    cout << "Result: " << sol.splitArray(nums, m) << endl;

    return 0;
}

