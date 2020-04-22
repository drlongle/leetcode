/*
560. Subarray Sum Equals K
Medium

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> cnt;
        for (int n: nums) {
            sum += n;
            if (sum == k)
                ++res;
            auto it = cnt.find(sum-k);
            if (it != cnt.end())
                res += it->second;
            ++cnt[sum];
        }


        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Output: 2
    nums = {1,1,1}, k = 2;
    //cout << sol.subarraySum(nums, k) << endl;
    
    nums = {1}, k = 0;
    cout << sol.subarraySum(nums, k) << endl;
    
    return 0;
}
