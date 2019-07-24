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

class SegmentTree {
public:
    SegmentTree(int n_): n(n_) {
        x = ceil(log2(n));
        int max_size = 2*(int)pow(2, x) - 1;
        x = pow(2, x);
        data.resize(max_size, 0);
    }

    void add(int index, int low, int high, int begin, int end, int val) {
        if (low > end || begin > high)
            return;
        if (begin <= low && high <= end) {
            data[index] += val;
            return;
        }
        int mid = (low + high) / 2;
        add(2*index + 1, low, mid, begin, end, val);
        add(2*index + 2, mid + 1, high, begin, end, val);
    }

    void add(int begin, int end, int val) {
        add(0, 1, x, begin, end, val);
    }

    int get_data(int index, int low, int high, int begin, int end, int val) {
        val += data[index];
        if (begin <= low && high <= end)
            return val;
        if (low > end || begin > high)
            return 0;
        int mid = (low + high) / 2;
        return get_data(2*index+1, low, mid, begin, end, val)
            + get_data(2*index+2, mid+1, high, begin, end, val);
    }

    int get_data(int index) {
        return get_data(0, 1, x, index, index, 0);
    }

    vector<int> data;
    int x, n;
};


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        SegmentTree seg(n);
        for (auto& booking: bookings) {
            seg.add(booking[0], booking[1], booking[2]);
        }
        vector<int> res;
        for (int i = 1; i <= n; ++i)
            res.emplace_back(seg.get_data(i));
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

