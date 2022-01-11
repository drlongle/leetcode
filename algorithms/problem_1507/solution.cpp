/*
1507. Reformat Date
Easy

Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.

Example 1:
Input: date = "20th Oct 2052"
Output: "2052-10-20"

Example 2:
Input: date = "6th Jun 1933"
Output: "1933-06-06"

Example 3:
Input: date = "26th May 1960"
Output: "1960-05-26"

Constraints:
The given dates are guaranteed to be valid, so no error handling is necessary.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        vector<string> months = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        istringstream iss(date);
        string year, month, day;
        getline(iss, day, ' ');
        getline(iss, month, ' ');
        getline(iss, year, ' ');
        ostringstream oss;
        oss << year << '-';
        for (int i = 1; i <= 12; ++i) {
            if (month == months[i]) {
                if (i < 10)
                    oss << '0';
                oss << i;
                break;
            }
        }
        oss << '-';

        int day_num = 0;
        for (char ch: day) {
            if (!isdigit(ch))
                break;
            day_num = day_num * 10 + ch - '0';
        }
        if (day_num < 10)
            oss << '0';
        oss << day_num;

        return oss.str();
    }
};

int main() {
    Solution sol;
    string date;

    date = "20th Oct 2052";
    cout << sol.reformatDate(date) << endl;

    date = "6th Jun 1933";
    cout << sol.reformatDate(date) << endl;

    return 0;
}
