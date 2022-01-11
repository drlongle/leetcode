/*
1128. Number of Equivalent Domino Pairs
Easy

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d]
if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can
be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
and dominoes[i] is equivalent to dominoes[j].

Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
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

class Solution {
public:
    int fact(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res += i;
        return res;
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> counts;
        for (const auto& d: dominoes) {
            auto mm = minmax(d[0], d[1]);
            ++counts[mm];
        }

        int res = 0;

        for (auto& p: counts) {
            if (p.second > 1)
                res += fact(p.second-1);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dominoes;

    // Expected: 1
    dominoes = {{1,2},{2,1},{3,4},{5,6}};

    cout << "Result: " << sol.numEquivDominoPairs(dominoes) << endl;

    return 0;
}

