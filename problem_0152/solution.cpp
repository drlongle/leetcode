/*
152. Maximum Product Subarray
Total Accepted: 61649 Total Submissions: 273660 Difficulty: Medium

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
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
    int maxProduct(vector<int>& nums) {
        int nsize = nums.size();
        vector<int> down = vector<int>(nsize, 1);

        int res = nums[0];
        int temp = 1;
        int total_product = 1;
        for (int i = 0; i < nsize; ++i)
        {
            temp = temp ? temp*nums[i] : nums[i];
            total_product *= nums[i];
            if (total_product > res)
                res = total_product;
        }

        temp = 1;
        for (int i = nsize-1; i >= 0; --i)
        {
            temp = temp ? temp*nums[i] : nums[i];
            down[i] = temp;
        }

        int up_index, down_index;
        for (up_index = 0; up_index < nsize; ++up_index)
            if (nums[up_index] != 1 && nums[up_index] != -1)
                break;
        for (down_index = nsize-1; down_index >= 0; --down_index)
            if (nums[down_index] != 1 && nums[down_index] != -1)
                break;
        if (up_index == nsize)
            return res;

        for (int i = up_index; i < nsize; ++i)
        {
            int dividend = down[i];
            if (dividend > res)
                res = dividend;
            for (int j = i; j <= down_index && nums[j]; ++j)
            {
                int divisor = (j == nsize-1 ? 1 : down[j+1]);
                if (divisor == 0 || divisor == 1)
                    continue;
                int temp = dividend / divisor;
                if (temp > res)
                    res = temp;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = sol.maxProduct(nums);
    cout << "Result: " << res << endl;

    return 0;
}

