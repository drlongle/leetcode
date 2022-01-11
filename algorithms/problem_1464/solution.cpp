/*
1464. Maximum Product of Two Elements in an Array
Easy

Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

Example 1:
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:
Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

Example 3:
Input: nums = [3,7]
Output: 12

Constraints:
2 <= nums.length <= 500
1 <= nums[i] <= 10^3
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
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num: nums) {
            if (pq.size() < 2)
                pq.push(num);
            else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
        int n1 = pq.top(); pq.pop();
        int n2 = pq.top();
        return (n1-1) * (n2-1);
    }
    
    int maxProduct2(vector<int>& nums) {
        int n = nums.size(), res = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j) {
                res = max(res, (nums[i]-1)*(nums[j]-1));
            }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
