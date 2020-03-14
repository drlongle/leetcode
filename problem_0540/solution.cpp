/*
540. Single Element in a Sorted Array
Medium

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.
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
    int singleNonDuplicate(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            int cnt = 1;
            if (i > 0 && nums[i] == nums[i-1])
                ++cnt;
            if (i < sz-1 && nums[i] == nums[i+1])
                ++cnt;
            if (cnt < 2)
                return nums[i];
        }
        return 0;
    }
};

int main() {
    Solution sol;
    return 0;
}
