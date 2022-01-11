/*
334. Increasing Triplet Subsequence
Difficulty: Medium

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 <= i < j < k <= n-1 else return false. 

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false. 
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
    bool increasingTriplet(vector<int>& nums) {
        int n_size = static_cast<int>(nums.size());
        if (n_size < 2) return false;
        int min_so_far = nums[0];
        int candidate;
        bool has_candidate = false;

        if (nums[1] > nums[0]) {
            has_candidate = true;
            candidate = nums[1];
        } else if (nums[1] < nums[0])
            min_so_far = nums[1];

        for (int i = 2; i < n_size; ++i)
        {
            if (has_candidate && candidate < nums[i]) return true;
            if (min_so_far > nums[i])
                min_so_far = nums[i];
            else if (min_so_far < nums[i]) {
                if (!has_candidate || (has_candidate && candidate > nums[i]))
                    candidate = nums[i];
                has_candidate = true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> input;

    input = {1,2,3,4,5};
    cout << "Result: " << boolalpha << sol.increasingTriplet(input) << endl;

    return 0;
}
