/*
871. Minimum Number of Refueling Stops
Hard

A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0]
miles east of the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses
1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?

If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

Example 1:
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.

Example 2:
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).

Example 3:
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation:
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.

Note:
1 <= target, startFuel, stations[i][1] <= 10^9
0 <= stations.length <= 500
0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    struct Entry {
        Entry(int s, int i, int f): stop(s), index(i), fuel(f) {}
        bool operator<(const Entry& other) const {
            return stop > other.stop || (stop == other.stop && index < other.index);
        }
        int stop, index, fuel;
    };

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<Entry> q;
        q.emplace(0, -1, startFuel);
        int sz = stations.size();
        int seen[1000] = {};

        while (!q.empty()) {
            auto [stop, index, fuel] = q.top();
            q.pop();
            int dist = (index < 0 ? 0 : stations[index][0]) + fuel;
            if (dist >= target) {
                return stop;
            }
            for (auto i = index + 1; i < sz && dist >= stations[i][0]; ++i) {
                int fuel = dist - stations[i][0];
                if (seen[i] <= fuel) {
                    seen[i] = fuel;
                    q.emplace(stop + 1, i, fuel + stations[i][1]);
                }
            }
        }

        return -1;
    }
};

int main() {
    int target, startFuel;
    vector<vector<int>> stations;

    // Output: 0
    {
        Solution sol;
        target = 1, startFuel = 1, stations = {};
        cout << sol.minRefuelStops(target, startFuel, stations) << endl;
    }

    // Output: -1
    {
        Solution sol;
        target = 100, startFuel = 1, stations = {{10,100}};
        cout << sol.minRefuelStops(target, startFuel, stations) << endl;
    }

    // Output: 2
    {
        Solution sol;
        target = 100, startFuel = 10, stations = {{10,60},{20,30},{30,30},{60,40}};
        cout << sol.minRefuelStops(target, startFuel, stations) << endl;
    }

    // Output: 32
    {
        Solution sol;
        target = 1000, startFuel = 36;
        stations = {{7,13},{10,11},{12,31},{22,14},{32,26},{38,16},{50,8},{54,13},{75,4},{85,2},{88,35},{90,9},{96,35},{103,16},{115,33},{121,6},{123,1},{138,2},{139,34},{145,30},{149,14},{160,21},{167,14},{188,7},{196,27},{248,4},{256,35},{262,16},{264,12},{283,23},{297,15},{307,25},{311,35},{316,6},{345,30},{348,2},{354,21},{360,10},{362,28},{363,29},{367,7},{370,13},{402,6},{410,32},{447,20},{453,13},{454,27},{468,1},{470,8},{471,11},{474,34},{486,13},{490,16},{495,10},{527,9},{533,14},{553,36},{554,23},{605,5},{630,17},{635,30},{640,31},{646,9},{647,12},{659,5},{664,34},{667,35},{676,6},{690,19},{709,10},{721,28},{734,2},{742,6},{772,22},{777,32},{778,36},{794,7},{812,24},{813,33},{815,14},{816,21},{824,17},{826,3},{838,14},{840,8},{853,29},{863,18},{867,1},{881,27},{886,27},{894,26},{917,3},{953,6},{956,3},{957,28},{962,33},{967,35},{972,34},{984,8},{987,12}};
        cout << sol.minRefuelStops(target, startFuel, stations) << endl;
    }

    // Output: 5
    {
        Solution sol;
        target = 1000, startFuel = 299;
        stations = {{14,123},{145,203},{344,26},{357,68},{390,35},{478,135},{685,108},{823,186},{934,217},{959,80}};
        cout << sol.minRefuelStops(target, startFuel, stations) << endl;
    }

    return 0;
}
