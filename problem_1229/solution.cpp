/*
1229. Meeting Scheduler

Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.  

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

Example 1:
Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]

Example 2:
Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
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
    optional<vector<int>> overlap(const vector<int>& s1, const vector<int>& s2) {
        if (s1[0] >= s2[1] || s2[0] >= s1[1])
            return nullopt;
        else
            return vector<int>{max(s1[0], s2[0]), min(s1[1], s2[1])};
    }
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        auto lambda = [] (const vector<int>& s1, const vector<int>& s2) {return s1[0] <= s2[0];};
        sort(begin(slots1), end(slots1), lambda);
        sort(begin(slots2), end(slots2), lambda);
        for (size_t i1 = 0, i2 = 0; i1 < slots1.size() && i2 < slots2.size(); ) {
            auto res = overlap(slots1[i1], slots2[i2]);
            if (res && res.value()[1] - res.value()[0] >= duration) {
                res.value()[1] = res.value()[0] + duration;
                return res.value();
            } if (lambda(slots1[i1], slots2[i2]))
                ++i1;
            else
                ++i2;
        }
        return vector<int>();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> slots1, slots2;
    int duration;
    slots1 = {{10,50},{60,120},{140,210}}, slots2 = {{0,15},{60,70}}, duration = 8;
    slots1 = {{10,50},{60,120},{140,210}}, slots2 = {{0,15},{60,70}}, duration = 12;

    auto res = sol.minAvailableDuration(slots1, slots2, duration);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
