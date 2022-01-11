/*
976. Largest Perimeter Triangle
Difficulty: Easy

Given an array A of positive lengths, return the largest perimeter of a
triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

Example 1:
Input: [2,1,2]
Output: 5

Example 2:
Input: [1,2,1]
Output: 0

Example 3:
Input: [3,2,3,4]
Output: 10

Example 4:
Input: [3,6,2,3]
Output: 8
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
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int nsize = nums.size();
        int res = 0;
        for (int i = nsize-1; i >= 2; --i) {
            int a = nums[i];
            for (int j = i-1; j >= 1; --j) {
                int b = nums[j];
                int c = nums[j-1];
                if (a+b > c && b+c > a && c+a > b) {
                    return a + b + c;
                }
                
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> nums;
    
    // Expected: 5
    nums = {2,1,2};
    
    // Expected: 8
    nums = {3,6,2,3};
    
    // Expected: 10
    nums = {3,2,3,4};
    
    cout << "Result: " << sol.slow_largestPerimeter(nums) << ", " << sol.largestPerimeter(nums) << endl;
    
    return 0;
}
