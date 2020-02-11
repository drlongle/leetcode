/*
1344. Angle Between Hands of a Clock
Medium

Given two numbers, hour and minutes. Return the smaller angle (in sexagesimal units) formed between the hour and the minute hand.

Example 1:
Input: hour = 12, minutes = 30
Output: 165

Example 2:
Input: hour = 3, minutes = 30
Output: 75

Example 3:
Input: hour = 3, minutes = 15
Output: 7.5

Example 4:
Input: hour = 4, minutes = 50
Output: 155

Example 5:
Input: hour = 12, minutes = 0
Output: 0

Constraints:
1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.
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
    double angleClock(int hour, int minutes) {
        double angle_m = 360 * minutes / 60;
        double angle_h = (double) 360 * hour / 12 + (double) 360 * minutes / 60 / 12;
        double angle = abs(angle_m - angle_h);
        if (angle >= 180)
            angle = 360 - angle;
        return angle;
    }
};

int main() {
    Solution sol;
    int hour, minutes;

    // Output: 165
    hour = 12, minutes = 30;

    // Output: 75
    //hour = 3, minutes = 30;

    // Output: 7.5
    //hour = 3, minutes = 15;

    // Output: 155
    //hour = 4, minutes = 50;

    // Output: 0
    //hour = 12, minutes = 0;

    cout << sol.angleClock(hour, minutes) << endl;
    
    return 0;
}
