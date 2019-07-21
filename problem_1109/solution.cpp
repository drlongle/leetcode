/*
1109. Corporate Flight Bookings
Difficulty: Medium

There are n flights, and they are labeled from 1 to n.
We have a list of flight bookings.  The x-th booking bookings[x] = [i, j, k]
means that we booked k seats from flights labeled i to j inclusive.

Return an array answer of length n, representing the number of seats booked
on each flight in order of their label.
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

struct Interval {
    int begin, end, seats;
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        list<Interval> intervals;
        
        for (const auto& booking: bookings) {
            Interval intval{booking[0], booking[1], booking[2]};
            auto it = intervals.begin();
            bool inserted = false;
            for (; it != intervals.end(); ++it) {
                inserted = false;
                if (it->begin > intval.end) {
                    intervals.insert(it, intval);
                    inserted = true;
                    break;
                } if (it->end < intval.begin)
                    continue;
                if (it->begin < intval.begin) {
                    intervals.insert(it, {it->begin, intval.begin-1, it->seats});
                    it->begin = intval.begin;
                } else if (intval.begin < it->begin) {
                    intervals.insert(it, {intval.begin, it->begin-1, intval.seats});
                    intval.begin = it->begin;
                }

                if (it->end < intval.end) {
                    it->seats += intval.seats;
                    intval.begin = it->end+1;
                } else if (it->end == intval.end) {
                    it->seats += intval.seats;
                    inserted = true;
                    break;
                } else {
                    intervals.insert(it, {intval.begin, intval.end, it->seats + intval.seats});
                    it->begin = intval.end+1;
                    inserted = true;
                    break;
                }
            }
            if (!inserted)
                intervals.emplace_back(intval);
        }

        vector<int> res;
        int expected = 1;
        for (const auto& intval: intervals) {
            while (expected < intval.begin) {
                res.emplace_back(0);
                ++expected;
            }
            for (int i = intval.begin; i <= intval.end; ++i)
                res.emplace_back(intval.seats);
            expected = intval.end + 1;
        }
        while (expected++ <= n)
            res.emplace_back(0);


        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> bookings;
    vector<int> res;
    int n;

    // Expected: [10,55,45,25,25]
    bookings = {{1,2,10},{2,3,20},{2,5,25}}, n = 5;

    // 23 / 63 test cases passed.
    // Expected: [0,75]
    bookings = {{2,2,30},{2,2,45}}, n = 2;

    // Expected: [15,105,105,0]
    bookings = {{2,3,30},{2,3,45},{2,3,15},{1,3,15}}, n = 4;

    // [70,80,30,20]
    bookings = {{1,3,20},{4,4,10},{1,2,50},{2,4,10}}, n = 4;

    // 27 / 63 test cases passed
    // Expected: [85,100,140,40]
    bookings = {{2,3,15},{1,3,50},{3,4,40},{1,3,35}}, n = 4;

    res = sol.corpFlightBookings(bookings, n);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));

    return 0;
}

