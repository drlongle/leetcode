/*
53. Maximum Subarray
Total Accepted: 116338 Total Submissions: 314913 Difficulty: Medium

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,1,2,1] has the largest sum = 6.

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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
    int maxSubArray(vector<int>& nums)
    {
        int running = 0;
        int res = numeric_limits<int>::min(), nsize = nums.size();

        for (int i = 0; i < nsize; ++i)
        {
            if (running < 0)
                running = 0;
            running += nums[i];
            if (res < running)
                res = running;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = sol.maxSubArray(nums);

    cout << "Result: " << res << endl;

    return 0;
}

