/*
1360. Number of Days Between Two Dates
Easy

Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

Example 1:
Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1

Example 2:
Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15

Constraints:
The given dates are valid dates between the years 1971 and 2100.
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
    bool is_leap_year(int year) {
        if (year % 4 != 0)
            return false;
        if (year % 100 != 0)
            return true;
        if (year % 400 != 0)
            return false;
        return true;
    }

    
    int month_days(int month, int year) {
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
    
    int count_days(string& date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int days = 0;
        for (int y = 1971; y < year; ++y) {
            days += 365 + is_leap_year(y);
        }

        for (int m = 1; m < month; ++m)
            days += month_days(m, year);
        
        days += day;
        
        return days;
    }
    
    int daysBetweenDates(string date1, string date2) {
        return abs(count_days(date2) - count_days(date1));
    }
};

int main() {
    Solution sol;
    string date1, date2;

    // Output: 1
    date1 = "2019-06-29", date2 = "2019-06-30";

    // Output: 15
    date1 = "2020-01-15", date2 = "2019-12-31";

    cout << sol.daysBetweenDates(date1, date2) << endl;
    
    return 0;
}
