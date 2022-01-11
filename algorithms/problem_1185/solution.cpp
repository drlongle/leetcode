/*
1185. Day of the Week
Easy

Given a date, return the corresponding day of the week for that date.
The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}. 

Example 1:
Input: day = 31, month = 8, year = 2019
Output: "Saturday"

Example 2:
Input: day = 18, month = 7, year = 1999
Output: "Sunday"

Example 3:
Input: day = 15, month = 8, year = 1993
Output: "Sunday"
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

    int leap_year(int year) {
        if (year % 400 == 0)
            return true;
        if ((year % 4 != 0) || (year % 100 == 0))
            return false;
        else
            return true;
    }

    int days_in_year(int year) {
        return leap_year(year) ? 366 : 365;
    }
    
    int days_in_month(int month, int year) {
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
                return leap_year(year) ? 29 : 28;
            default:
                return 30;
        }
    }
    
    // 1 January 1971 is a Friday
    string dayOfTheWeek(int day, int month, int year) {
        int days = day - 1;
        for (int i = 1971; i < year; ++i) {
            days = (days + days_in_year(i)) % 7;
        }
        
        for (int i = 1; i < month; ++i) {
            days = (days + days_in_month(i, year)) % 7;
        }

        vector<string> weekdays = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        
        return weekdays[days];
    }
};

int main() {
    Solution sol;
    int day, month, year;
    
    // Output: "Saturday"
    day = 31, month = 8, year = 2019;

    // Output: "Sunday"
    //day = 18, month = 7, year = 1999;

    // Output: "Sunday"
    //day = 15, month = 8, year = 1993;

    // Output: Monday
    //day = 10, month = 1, year = 1990;

    // Output: Tuesday
    //day = 1, month = 2, year = 2001;
    
    // Output: Friday
    //day = 1, month = 1, year = 1971;
    //day = 1, month = 3, year = 1971;
    //day = 11, month = 5, year = 1971;
    //day = 11, month = 5, year = 1972;
    //day = 11, month = 5, year = 1973;
    //day = 11, month = 5, year = 1974;
    
    // Output: Thursday
    //day = 14, month = 3, year = 2000;

    // Output: Thursday
    //day = 28, month = 2, year = 1980;
    
    cout << "Result: " << sol.dayOfTheWeek(day, month, year) << endl;
    
    return 0;
}
