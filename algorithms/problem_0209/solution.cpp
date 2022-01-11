/*
209. Minimum Size Subarray Sum  
Total Accepted: 38482 Total Submissions: 142630 Difficulty: Medium

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum >= s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
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

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        pair<int,int> result = make_pair(-1,-1);
        int sum = 0;
        int n_size = static_cast<int>(nums.size());
        int head = 0, tail = 0;
        for ( ; tail < n_size; ++tail) {
            sum += nums[tail];
            for ( ; sum >= s; ++head) {
                sum -= nums[head];
                if (sum < s) {
                    if (result.first < 0 ||
                        result.second-result.first > tail-head)
                        result = make_pair(head, tail);
                }
            }
        }

        if (result.first < 0) return 0;
        else return result.second-result.first+1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int s;

    nums = {2,3,1,2,4,3};
    s = 7;
    cout << "Result: " << sol.minSubArrayLen(s,nums) << endl;

    return 0;
}

