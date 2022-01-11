/*
503. Next Greater Element II
Medium

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; ++i)
            nums.emplace_back(nums[i]);
        set<int> lookup;
        vector<int> res(sz);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int n = nums[i];
            for (auto it = lookup.begin(); it != lookup.end() && *it < n; ) {
                it = lookup.erase(it);
            }
            if (i < sz) {
                auto it = lookup.upper_bound(n);
                if (it != lookup.end())
                    res[i] = *it;
                else
                    res[i] = -1;
            }
            lookup.insert(n);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: {2,-1,2]
    nums =  {1,2,1};
    auto res = sol.nextGreaterElements(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
