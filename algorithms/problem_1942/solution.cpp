/*
1942. The Number of the Smallest Unoccupied Chair
Medium

There is a party where n friends numbered from 0 to n - 1 are attending. There
is an infinite number of chairs in this party that are numbered from 0 to
infinity. When a friend arrives at the party, they sit on the unoccupied chair
with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will
sit on chair number 2. When a friend leaves the party, their chair becomes
unoccupied at the moment they leave. If another friend arrives at that same
moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali,
leavingi], indicating the arrival and leaving times of the ith friend
respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

Example 1:
Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation:
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.

Example 2:
Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation:
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.

Constraints:
n == times.length
2 <= n <= 10^4
times[i].length == 2
1 <= arrivali < leavingi <= 10^5
0 <= targetFriend <= n - 1
Each arrivali time is distinct.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

struct node {
    node(int b, int e) : begin(b), end(e), count(0) {
        if (e > b) {
            int mid = (b + e) / 2;
            children.emplace_back(b, mid);
            children.emplace_back(mid + 1, end);
        }
    }

    bool is_full() { return end - begin + 1 == count; }

    int reserve() {
        if (is_full())
            return -1;
        ++count;
        if (end == begin)
            return begin;
        else if (int ret = children[0].reserve(); ret >= 0)
            return ret;
        else
            return children[1].reserve();
    }

    void free(int n) {
        if (n < begin || n > end)
            return;
        --count;
        if (end == begin) {
            return;
        } else {
            int mid = (begin + end) / 2;
            if (n <= mid)
                children[0].free(n);
            else
                children[1].free(n);
        }
    }

    int begin, end, count;
    vector<node> children;
};

class Solution {
  public:
    struct Event {
        int time;
        int index;
        bool come;
    };
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        vector<Event> events;
        vector<int> seats(times.size(), -1);
        for (int i = 0, n = times.size(); i < n; ++i) {
            events.emplace_back(times[i][0], i, true);
            events.emplace_back(times[i][1], i, false);
        }

        node n(0, times.size());
        ranges::sort(events, [](const auto &e1, const auto &e2) {
            return (e1.time < e2.time) ||
                   ((e1.time == e2.time) &&
                    (!e1.come && (e2.come || e1.index < e2.index)));
        });
        for (auto &e : events) {
            auto &seat = seats[e.index];
            if (e.come) {
                seat = n.reserve();
                if (e.index == targetFriend)
                    return seat;
            } else {
                n.free(seat);
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times;
    int targetFriend;

    times = {{1, 4}, {2, 3}, {4, 6}}, targetFriend = 1;
    cout << sol.smallestChair(times, targetFriend) << endl;

    times = {{3, 10}, {1, 5}, {2, 6}}, targetFriend = 0;
    cout << sol.smallestChair(times, targetFriend) << endl;

    times = {{33889, 98676}, {80071, 89737}, {44118, 52565}, {52992, 84310},
             {78492, 88209}, {21695, 67063}, {84622, 95452}, {98048, 98856},
             {98411, 99433}, {55333, 56548}, {65375, 88566}, {55011, 62821},
             {48548, 48656}, {87396, 94825}, {55273, 81868}, {75629, 91467}};
    targetFriend = 6;
    cout << sol.smallestChair(times, targetFriend) << endl;

    times = {
        {3, 100000},  {37, 100000}, {34, 100000}, {16, 100000}, {28, 100000},
        {19, 100000}, {14, 100000}, {29, 100000}, {5, 100000},  {9, 100000},
        {25, 100000}, {18, 100000}, {31, 100000}, {17, 100000}, {12, 100000},
        {36, 100000}, {30, 100000}, {13, 100000}, {27, 100000}, {10, 100000},
        {21, 100000}, {38, 100000}, {11, 100000}, {46, 100000}, {2, 100000},
        {33, 100000}, {20, 100000}, {8, 100000},  {35, 100000}, {43, 100000},
        {23, 100000}, {22, 100000}, {15, 100000}, {44, 100000}, {45, 100000},
        {7, 100000},  {24, 100000}, {42, 100000}, {6, 100000},  {1, 100000},
        {26, 100000}, {39, 100000}, {32, 100000}, {40, 100000}, {41, 100000},
        {4, 100000}};
    targetFriend = 23;
    cout << sol.smallestChair(times, targetFriend) << endl;

    return 0;
}
