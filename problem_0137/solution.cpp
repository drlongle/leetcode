/*
137. Single Number II  
Total Accepted: 82658 Total Submissions: 219300 Difficulty: Medium

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        int next_ones, next_twos;
        for (const auto& n: nums) {
            next_ones = (ones & ~n) | (n & ~ones & ~twos);
            next_twos = (~n & twos) | (ones & n);
            ones = next_ones;
            twos = next_twos;
        }
        return ones;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {3,6,3,3};
    cout << "Result: " << sol.singleNumber(nums) << endl;

    return 0;
}

