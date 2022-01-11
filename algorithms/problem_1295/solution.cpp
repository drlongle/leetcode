/*
1295. Find Numbers with Even Number of Digits
Easy

Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:
Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
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
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int n: nums) {
            cnt += (to_string(n).size() % 2 == 0);
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Expected: 2
    nums = {12,345,2,6,7896};

    // Expected: 1
    nums = {555,901,482,1771};

    // Expected: 1
    nums = {10};
    
    cout << "Result: " << sol.findNumbers(nums) << endl;
    
    return 0;
}
