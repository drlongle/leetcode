/*
41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3, and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
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
    int firstMissingPositive(vector<int>& nums) {
        int minv = -1;
        for (int& n: nums) {
            if (n > 0)
                minv = (minv < 0) ? n : min(n, minv);
            else
                n = 0;
        }

        if (minv < 0 || minv > 1)
            return 1;

        int sz = nums.size();
        for (int n: nums) {
            if (n <= 0)
                n += 1 + sz;
            if (n > 0 && n <= sz) {
                int index = n - minv;
                int& ni = nums[index];
                ni = min(ni, sz);
                if (ni >= 0)
                    ni -= 1 + sz;
            }
        }

        for (int i = 0; i < sz; ++i) {
            if (nums[i] >= 0)
                return i+1;
        }

        return sz+1;
    }
};

int main()
{
    Solution sol;
    vector<int> input;

    // Expected: 2
    input = {3,4,-1,1};
    //cout << "Result: " << sol.firstMissingPositive(input) << endl;

    // Expected: 2
    input = {1};
    //cout << "Result: " << sol.firstMissingPositive(input) << endl;

    // Expected: 2
    input = {3,3,1,4,0};
    //cout << "Result: " << sol.firstMissingPositive(input) << endl;

    // Expected: 2
    input = {1,1,1};
    //cout << "Result: " << sol.firstMissingPositive(input) << endl;

    // Expected: 2
    input = {3,1};
    cout << "Result: " << sol.firstMissingPositive(input) << endl;

    return 0;
}
