/*
628. Maximum Product of Three Numbers
Easy

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6

Example 2:
Input: [1,2,3,4]
Output: 24
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
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int res = nums[n-3]*nums[n-2]*nums[n-1];
        res = max(res, nums[0]*nums[1]*nums[n-1]);
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
