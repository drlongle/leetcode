/*
239. Sliding Window Maximum  
Total Accepted: 25959 Total Submissions: 94138 Difficulty: Hard

Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in 
the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 <= k <= input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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

#define ll long long
#define ull unsigned long long

using namespace std;

struct Entry
{
    Entry(int p, int v): position(p), value(v) { }
    int position;
    int value;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<Entry> candidates;
        int index, nsize = static_cast<int>(nums.size());
        for (index = 0; index < nsize; ++index) {
            while (candidates.size() && candidates.back().value < nums[index])
                candidates.pop_back();
            candidates.emplace_back(index, nums[index]);
            if (index+1 < k)
                continue;
            while (candidates.front().position+k <= index)
                candidates.pop_front();
            result.emplace_back(candidates.front().value);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums, result;
    int k;

    nums = {1,3,-1,-3,5,3,6,7};
    k = 3;
    result = sol.maxSlidingWindow(nums,k);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

