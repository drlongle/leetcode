/*
238. Product of Array Except Self
Difficulty: Medium

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n_size = static_cast<int>(nums.size());
        vector<int> forward(n_size, 1), backward(n_size,1), result(n_size);

        for (int i = 1; i < n_size; ++i)
            forward[i] = forward[i-1]*nums[i-1];
        for (int i = n_size-2; i >= 0; --i)
            backward[i] = backward[i+1]*nums[i+1];

        for (int i = 0; i < n_size; ++i)
            result[i] = forward[i]*backward[i];

        return result;
    }

    vector<int> productExceptSelf_New(vector<int>& nums) {
        int n_size = static_cast<int>(nums.size());
        vector<int> result(n_size, 1);

        for (int i = 1; i < n_size; ++i)
            result[i] = result[i-1]*nums[i-1];

        int temp = 1;
        for (int i = n_size-2; i >= 0; --i)
        {
            temp *= nums[i+1];
            result[i] *= temp;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> input;

    input = {1,2,3,4};
    vector<int> output = sol.productExceptSelf_New(input);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, ", "));

    return 0;
}
