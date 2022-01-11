/*
307. Range Sum Query - Mutable
Total Accepted: 13491 Total Submissions: 74750 Difficulty: Medium

Given an integer array nums, find the sum of the elements between indices
i and j (i <= j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
    The array is only modifiable by the update function.
    You may assume the number of calls to update and sumRange function is distributed evenly.
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

class NumArray {
public:
    NumArray(vector<int> &nums)
    {
        size_t n = 0, nsize = nums.size();
        while (n < nsize)
        {
            size_t array_size = min(max_array_size, nsize-n);
            vector<int> numbers(array_size), prefix_sum(array_size, 0);
            for (size_t i = 0; i < array_size; ++i)
            {
                numbers[i] = nums[n+i];
                prefix_sum[i] = (i > 0 ? prefix_sum[i-1] : 0) + numbers[i];
            }
            m_nums.emplace_back(numbers);
            m_prefix_sum.emplace_back(prefix_sum);
            n += array_size;
        }
    }

    void update(int i, int val)
    {
        size_t index = i / max_array_size;
        int size = m_nums[index].size();
        int diff = val - m_nums[index][i % max_array_size];
        if (diff == 0)
            return;
        for (int ii = i % max_array_size; ii < size; ++ii)
            m_prefix_sum[index][ii] += diff;
        m_nums[index][i % max_array_size] = val;
    }

    int sumRange(int i, int j)
    {
        int res = 0;
        int index = j / max_array_size;
        for (int ii = 0; ii < index; ++ii)
            res += m_prefix_sum[ii].back();
        res += m_prefix_sum[index][j % max_array_size];

        if (i > 0)
        {
            --i;
            index = i / max_array_size;
            for (int ii = 0; ii < index; ++ii)
                res -= m_prefix_sum[ii].back();
            res -= m_prefix_sum[index][i % max_array_size];
        }

        return res;
    }

    vector<vector<int>> m_nums;
    vector<vector<int>> m_prefix_sum;
    static const size_t max_array_size;
};

const size_t NumArray::max_array_size = 1000;

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main()
{
    vector<int> nums;
    NumArray numArray(nums);
    int res;

    // Expected: [-8,-5,0]
    nums = {9,-8};
    numArray = NumArray(nums);
    numArray.update(0,3);
    res = numArray.sumRange(1,1);
    cout << "Result: " << res << endl;
    res = numArray.sumRange(0,1);
    cout << "Result: " << res << endl;
    numArray.update(1,-3);
    res = numArray.sumRange(0,1);
    cout << "Result: " << res << endl;

    return 0;
}

