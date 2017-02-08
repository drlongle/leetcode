/*
217. Contains Duplicate
Total Accepted: 92128 Total Submissions: 221297 Difficulty: Easy

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct. 
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums);
};

bool Solution::containsDuplicate(vector<int>& nums)
{
    unordered_set<int> numbers;
    for (const auto& n: nums)
    {
        if (numbers.find(n) != numbers.end())
            return true;
        numbers.emplace(n);
    }
    return false;
}

int main()
{
    Solution sol;

    return 0;
}

