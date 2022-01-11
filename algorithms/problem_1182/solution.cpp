/*
1182. Shortest Distance to Target Color
Medium

You are given an array colors, in which there are three colors: 1, 2 and 3.
You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.

Example 1:
Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation: 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).

Example 2:
Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.
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
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> res;
        map<int, set<int>> table;
        for (int i = 0; i < static_cast<int>(colors.size()); ++i)
            table[colors[i]].emplace(i);
        for (auto& query: queries) {
            int index = query[0];
            int color = query[1];
            auto& entry = table[color];
            if (entry.empty()) {
                res.emplace_back(-1);
                continue;
            }
            auto it = entry.lower_bound(index);
            if (it == end(entry)) {
                res.emplace_back(abs(*entry.rbegin() - index));
            } else {
                int dist = *it - index;
                if (it != begin(entry)) {
                    dist = min(dist, abs(index - *(--it)));
                }
                res.emplace_back(dist);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> colors;
    vector<vector<int>> queries;
    
    // Output: [3,0,3]
    colors = {1,1,2,1,3,2,2,3,3}, queries = {{1,3},{2,2},{6,1}};

    // Output: [-1]
    //colors = {1,2}, queries = {{0,3}};

    auto res = sol.shortestDistanceColor(colors, queries);

    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    return 0;
}
