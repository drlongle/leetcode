/*
1094. Car Pooling
Medium

You are driving a vehicle that has capacity empty seats initially available for
passengers. The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location]
contains information about the i-th trip: the number of passengers that must be
picked up, and the locations to pick them up and drop them off.  The locations are
given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers
for all the given trips.

Example 1:
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2:
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true

Example 3:
Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true

Example 4:
Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
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

class SegmentTree {
public:
    SegmentTree(int n, int c) : capacity(c)
    {
        int x = ceil(log2(n));
        limit = pow(2, x) - 1;
        data.resize(2 * pow(2, x) - 1, 0);
    }

    bool add(int index, int low, int high, int begin, int end, int val)
    {
        if (low > end || begin > high)
            return true;

        // index > limit means that we only store data at the leaf nodes
        // i.e. we do not store data at internal nodes (parent nodes)
        if (begin <= low && high <= end && index > limit) {
            data[index] += val;
            return data[index] <= capacity;
        }

        int mid = (low + high) / 2;
        int t = data[index];
        data[index] = 0;
        return add(2 * index + 1, low, mid, begin, end, val + t)
               && add(2 * index + 2, mid + 1, high, begin, end, val + t);
    }

    bool add(int begin, int end, int val)
    {
        return add(0, 0, limit, begin, end, val);
    }

    vector<int> data;
    int limit, capacity;
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        SegmentTree seg(1000, capacity);

        for (auto& trip : trips) {
            if (!seg.add(trip[1], trip[2] - 1, trip[0]))
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> trips;
    int capacity;

    // Output: false
    trips = {{2, 1, 5}, {3, 3, 7}}, capacity = 4;

    // Output: true
    // trips = {{2,1,5},{3,3,7}}, capacity = 5;

    // Output: true
    // trips = {{2,1,5},{3,5,7}}, capacity = 3;

    // Output: true
    // trips = {{3,2,7},{3,7,9},{8,3,9}}, capacity = 11;

    // Output: false
    // trips = {{7,5,6},{6,7,8},{10,1,6}}, capacity = 16;

    cout << "Result: " << sol.carPooling(trips, capacity) << endl;

    return 0;
}
