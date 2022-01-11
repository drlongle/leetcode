/*
851. Loud and Rich
Medium

In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.

For convenience, we'll call the person with label x, simply "person x".

We'll say that richer[i] = [x, y] if person x definitely has more money than person y.
Note that richer may only be a subset of valid observations.

Also, we'll say quiet[x] = q if person x has quietness q.

Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with
the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.

Example 1:

Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation: 
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but
it isn't clear if they have more money than person 0.

answer[7] = 7.
Among all people that definitely have equal to or more money than person 7
(which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x])
is person 7.

The other answers can be filled out with similar reasoning.

Note:
1 <= quiet.length = N <= 500
0 <= quiet[i] < N, all quiet[i] are different.
0 <= richer.length <= N * (N-1) / 2
0 <= richer[i][j] < N
richer[i][0] != richer[i][1]
richer[i]'s are all different.
The observations in richer are all logically consistent.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> res, loud;
    vector<vector<int>> graph;

    void dfs(vector<int>& quiet, int id) {
        if (res[id] >= 0)
            return;
        res[id] = id;
        loud[id] = quiet[id];
        for (auto nid: graph[id]) {
            dfs(quiet, nid);
            if (loud[id] > loud[nid]) {
                res[id] = res[nid];
                loud[id] = loud[nid];
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        res.resize(n, -1);
        loud.resize(n, -1);
        graph.resize(n);
        for (auto& r: richer) {
            int x = r[0], y = r[1];
            graph[y].emplace_back(x);
        }
        for (int i = 0; i < n; ++i)
            dfs(quiet, i);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> richer;
    vector<int> quiet, res;

    // Output: {5,5,2,5,4,5,6,7}
    richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}}, quiet = {3,2,5,4,6,1,7,0};
    res = sol.loudAndRich(richer, quiet);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
