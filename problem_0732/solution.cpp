/*
731. My Calendar II
Medium

Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will
not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the
half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time
that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully
without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation:
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.

Note:
The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Interval {
    Interval(int s, int e, int c): start(s), end(e), cnt(c) {}
    int start, end, cnt;
};

class MyCalendarThree {
public:
    int book(int start, int end) {
        auto it = slots.begin();
        bool inserted = true;
        for ( ; it != slots.end() && end > it->start; ++it) {
            if ((it->start <= start && start < it->end) || (start <= it->start && it->start < end)) {
                if (start < it->start) {
                    slots.emplace(it, Interval(start, it->start, 1));
                    start = it->start;
                } else if (it->start < start) {
                    slots.emplace(it, Interval(it->start, start, it->cnt));
                    it->start = start;
                }
                ++(it->cnt);
                if (end < it->end) {
                    slots.emplace(next(it), Interval(end, it->end, it->cnt-1));
                    it->end = end;
                    inserted = false;
                    break;
                } else if (it->end < end) {
                    start = it->end;
                }
            }
        }

        if (inserted)
            slots.emplace(it, Interval(start, end, 1));

        it = max_element(slots.begin(), slots.end(), [] (auto& a, auto& b) {return a.cnt < b.cnt;});

        return it->cnt;
    }

    list<Interval> slots;
};

void test_1()
{
    vector<pair<int, int>> slots{{10,20},{50,60},{10,40},{5,15},{5,10},{25,55}};
    MyCalendarThree calendar;
    for (auto& slot: slots) {
        cout << boolalpha << slot.first << ", " << slot.second << " -> " << calendar.book(slot.first, slot.second) << endl;
    }
}
int main() {
    test_1();

    return 0;
}
