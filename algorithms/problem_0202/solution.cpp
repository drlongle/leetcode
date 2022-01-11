/*
202. Happy Number
Total Accepted: 74623 Total Submissions: 200599 Difficulty: Easy

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
    bool isHappy(int num) {
        unordered_set<int> seen;

        while (num != 1)
        {
            if (seen.find(num) != seen.end())
                return false;
            seen.emplace(num);
            int res = 0;
            while (num)
            {
                int t = num % 10;
                res += t*t;
                num /= 10;
            }
            num = res;
        } 
        return true;
    }
};

int main()
{
    Solution sol;
    int num;
    cout << "Input: ";
    cin >> num;
    cout << "Result: " << boolalpha << sol.isHappy(num) << endl;

    return 0;
}

