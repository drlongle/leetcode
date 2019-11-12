/*
1248. Count Number of Nice Subarrays
Medium

Given an array of integers nums and an integer k. A subarray is called nice
if there are k odd numbers on it. Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
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

    int get_head(vector<int>& nums, int head, int& count, int k, int ns) {
        while (head < ns) {
            if (nums[head] % 2 == 1)
                ++count;
            if (count == k)
                break;
            ++head;
        }
        return head;
    }

    int get_tail(vector<int>& nums, int head, int tail, int& count, int k, int ns) {
        while (tail < min(ns, head+1)) {
            if (nums[tail] % 2 == 1) {
                --count;
                break;
            }
            ++tail;
        }
        return tail;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int head = 0, next_head, next_tail = 0, tail = 0, count = 0, ns = nums.size();

        head = get_head(nums, 0, count, k, ns);
        while (head < ns) {
            next_head = head+1;
            while (next_head < ns) {
                if (nums[next_head] % 2 == 1)
                    break;
                ++next_head;
            }
            next_tail = get_tail(nums, head, tail, count, k, ns);
            res += (next_head - head) * (next_tail - tail + 1);
            tail = next_tail+1;
            head = next_head;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;
    
    // Output: 2
    nums = {1,1,2,1,1}, k = 3;

    // Output: 0
    //nums = {2,4,6}, k = 1;

    // Output: 16
    nums = {2,2,2,1,2,2,1,2,2,2}, k = 2;

    // Output: 13
    //nums = {2,2,1,2,1,2,1,1,2,1}, k = 2;

    cout << "Result: " << sol.numberOfSubarrays(nums, k) << endl;
    
    return 0;
}
