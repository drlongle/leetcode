/*
1133. Largest Unique Number
Difficulty; Easy

Given an array of integers A, return the largest integer that only occurs once.
If no integer occurs once, return -1.

Example 1:
Input: [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: 
The maximum integer in the array is 9 but it is repeated. The number 8 occurs
only once, so it's the answer.

Example 2:
Input: [9,9,8,8]
Output: -1
Explanation: 
There is no number that occurs only once.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> counts;

        for (auto& n: nums)
            ++counts[n];

        for (auto it = counts.rbegin(); it != counts.rend(); ++it) {
            if (it->second == 1)
                return it->first;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    
    nums = {5,7,3,9,4,9,8,3,1};

    nums = {9,9,8,8};
    
    cout << "Result: " << sol.largestUniqueNumber(nums) << endl;
    
    return 0;
}

