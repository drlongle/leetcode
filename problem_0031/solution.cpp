/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1
*/

#include <algorithm>
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
    void nextPermutation(vector<int>& nums)
    {
        int index, s_size = static_cast<int>(nums.size());
        for (index = s_size-2; index >= 0; --index) {
            if (nums[index] < nums[index+1])
                break;
        }
        if (index < 0) {
            sort(nums.begin(), nums.end());
        } else {
            int index2 = index+1;
            for (int i = index2+1; i < s_size; ++i)
            {
                if (nums[index2] > nums[i] && nums[i] > nums[index])
                    index2 = i;
            }
            swap(nums[index], nums[index2]);
            sort(nums.begin() + index +1, nums.end());
        }
    }
};


int main()
{
    Solution sol;
    vector<int> input{2, 3, 5, 4, 1};
    sol.nextPermutation(input);
    copy(input.begin(), input.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}

