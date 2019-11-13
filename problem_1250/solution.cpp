/*
1250. Check If It Is a Good Array
Hard

Given an array nums of positive integers. Your task is to select some subset of nums,
multiply each element by an integer and add all these numbers. The array is said to be good
if you can obtain a sum of 1 from the array by any possible subset and multiplicand.
Return True if the array is good otherwise return False.

Example 1:
Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1

Example 2:
Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1

Example 3:
Input: nums = [3,6]
Output: false
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

    int gcd(int a, int b) {
        if (a == 1 || b == 1)
            return 1;
        if (b > a)
            swap(a, b);
        int mod = a%b;
        if (mod == 0)
            return b;
        return gcd(a%b, b);
    }
    int gcd(vector<int>& nums) {
        while (nums.size() > 1) {
            int a = nums.back();
            nums.pop_back();
            int b = nums.back();
            nums.back() = gcd(a, b);
        }
        return nums.back();
    }
    bool isGoodArray(vector<int>& A) {
        int res = A[0];
        for (int a: A)
            res = gcd(res, a);
        return res == 1;
    }
    bool isGoodArray2(vector<int>& nums) {
        return gcd(nums) == 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: true
    nums = {12,5,7,23};

    // Output: true
    //nums = {29,6,10};
    
    // Output: false
    //nums = {3,6};

    cout << boolalpha << "Result: " << sol.isGoodArray(nums) << endl;
    
    return 0;
}
