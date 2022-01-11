/*
136. Single Number  
Total Accepted: 126844 Total Submissions: 254755 Difficulty: Medium

Given an array of integers, every element appears twice except for one. Find that single one.

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
       int result = 0;
       for (const auto& n: nums)
           result ^= n;
       return result;
    }
};

int main()
{
    Solution sol;

    return 0;
}

