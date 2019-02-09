/*
977. Squares of a Sorted Array
Difficulty: Easy

Given an array of integers A sorted in non-decreasing order, return an array
of the squares of each number, also in sorted non-decreasing order.

Example 1:
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> res;
        for (auto& n: nums)
            res.emplace(n*n);
        return vector<int>(begin(res), end(res));
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums;
    
    // Expected: 5
    nums = {9,4,2,10,7,8,8,1,9};
    
    // Expected: 2
    //nums = {4,8,12,16};
    
    // Expected: 1
    //nums = {100};0

    return 0;
}
