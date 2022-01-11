/*
1057. Campus Bikes
Medium

On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M.
Each worker and bike is a 2D coordinate on this grid.

Our goal is to assign a bike to each worker. Among the available bikes and workers,
we choose the (worker, bike) pair with the shortest Manhattan distance between each other,
and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the
same shortest Manhattan distance, we choose the pair with the smallest worker index;
if there are multiple ways to do that, we choose the pair with the smallest bike index).
We repeat this process until there are no available workers.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that
the i-th worker is assigned to.

Example 1:
Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: [1,0]
Explanation:
Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1.
So the output is [1, 0].

Example 2:
Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: [0,2,1]
Explanation:
Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2,
thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].

Note:
0 <= workers[i][j], bikes[i][j] < 1000
All worker and bike locations are distinct.
1 <= workers.length <= bikes.length <= 1000
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
        int worker, bike, distance;
        Entry(int w, int b, int d): worker(w), bike(b), distance(d) {}
        bool operator<(const Entry& other) const {
            bool res = distance < other.distance;
            res |= distance == other.distance && worker < other.worker;
            res |= distance == other.distance && bike < other.bike;
            return res;
        }
    };
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int wsize = workers.size(), bsize = bikes.size();
        vector<int> res(wsize, -1), taken(bsize, false);
        vector<vector<Entry>> candidates(wsize);
        for (int i = 0; i < wsize; ++i) {
            for (int j = 0; j < bsize; ++j) {
                candidates[i].emplace_back(i, j, abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]));
            }
        }

        for (auto& cand: candidates) {
            sort(begin(cand), end(cand));
        }

        set<Entry> table;
        for (int i = 0; i < wsize; ++i)
            table.emplace(candidates[i][0]);
        while (table.size()) {
            auto it = table.begin();
            int worker = it->worker;
            int bike = it->bike;
            table.erase(it);
            if (!taken[bike]) {
                taken[bike] = true;
                res[worker] = bike;
            } else {
                while (taken[candidates[worker].front().bike])
                    candidates[worker].erase(candidates[worker].begin());
                table.emplace(candidates[worker].front());
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> workers, bikes;
    vector<int> res;

    // Output: {1,0}
    workers = {{0,0},{2,1}}, bikes = {{1,2},{3,3}};
    res = sol.assignBikes(workers, bikes);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {0,2,1}
    workers = {{0,0},{1,1},{2,0}}, bikes = {{1,0},{2,2},{2,1}};
    res = sol.assignBikes(workers, bikes);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    workers = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}};
    bikes = {{0,999},{1,999},{2,999},{3,999},{4,999},{5,999},{6,999},{7,999},{8,999}};
    res = sol.assignBikes(workers, bikes);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
