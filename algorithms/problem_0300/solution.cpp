/*
300. Longest Increasing Subsequence  
Total Accepted: 25795 Total Submissions: 75441 Difficulty: Medium

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity? 
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seqlength(nums.size(),1);
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            int length = 1;
            for (int j = i-1; j >= 0; --j) {
                if (nums[j] < nums[i] && seqlength[j]+1 > length)
                    length = seqlength[j]+1;
            }
            seqlength[i] = length;
        }
        int result = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            if (seqlength[i] > result)
                result = seqlength[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Answer: " << sol.lengthOfLIS(nums) << endl;

    return 0;
}

