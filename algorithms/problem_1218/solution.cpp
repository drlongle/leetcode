/*
1218. Longest Arithmetic Subsequence of Given Difference
Medium

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
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
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> lookup;
        int res = 1;
        for (int n: arr) {
            int temp = max(lookup[n], 1 + lookup[n - difference]);
            res = max(res, temp);
            lookup[n] = temp;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int difference;

    // OUtput: 4
    arr = {1,2,3,4}, difference = 1;

    arr = {1,3,5,7}, difference = 1;

    arr = {1,5,7,8,5,3,4,2,1}, difference = -2;
        
    cout << "Result: " << sol.longestSubsequence(arr, difference) << endl;
    
    return 0;
}
