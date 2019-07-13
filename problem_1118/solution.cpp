/*
1118. Number of Days in a Month
Difficulty: Easy

Given a year Y and a month M, return how many days there are in that month.

Example 1:
Input: Y = 1992, M = 7
Output: 31

Example 2:
Input: Y = 2000, M = 2
Output: 29

Example 3:
Input: Y = 1900, M = 2
Output: 28

Note:
1583 <= Y <= 2100
1 <= M <= 12
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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
    bool is_leap_year(int year) {
        if (year % 4 != 0)
            return false;
        if (year % 100 != 0)
            return true;
        if (year % 400 != 0)
            return false;
        return true;
    }

    int numberOfDays(int year, int month) {
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return 30;
        }

        return 0;
    }
};

int main() {
    Solution sol;

    return 0;
}

