/*
1154. Day of the Year
Easy

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD,
return the day number of the year.

Example 1:
Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:
Input: date = "2019-02-10"
Output: 41

Example 3:
Input: date = "2003-03-01"
Output: 60

Example 4:
Input: date = "2004-03-01"
Output: 61
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
#include <numeric>
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
    bool is_leap_year(int year) {
        if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
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
    }
    
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        int res = 0;
        for (int m = 1; m < month; ++m)
            res += numberOfDays(year, m);
        res += day;
        
        return res;
    }
};

int main()
{
    Solution sol;
    string date;

    // Output: 9
    date = "2019-01-09";

    // Output: 41
    //date = "2019-02-10";

    // Output: 60
    //date = "2003-03-01";

    // Output: 61
    //date = "2004-03-01";
    
    cout << "Result: " << sol.dayOfYear(date) << endl;
    
    return 0;
}

