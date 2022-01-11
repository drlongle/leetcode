/*
254. Factor Combinations
Medium

Numbers can be regarded as the product of their factors.

For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].

Example 1:
Input: n = 1
Output: []

Example 2:
Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]

Example 3:
Input: n = 37
Output: []

Example 4:
Input: n = 32
Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]

Constraints:
1 <= n <= 10^8
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

    unordered_map<int, vector<vector<int>>> dp;
    vector<vector<int>> getFactors(int n) {
        if (n == 1)
            return {};

        auto it = dp.find(n);
        if (it != dp.end())
            return it->second;

        vector<vector<int>> res, subres;
        unordered_set<int> seen;

        auto extend = [this, &res] (int i, int j) {
            auto r = getFactors(j);
            for (auto& sr: r) {
                sr.emplace_back(i);
                sort(begin(sr), end(sr));
                res.emplace_back(move(sr));
            }
        };

        int limit = n/2;
        for (int i = 2; i <= limit; ++i) {
            if (n % i == 0 && !seen.count(i)) {
                int j = n / i;
                res.emplace_back(vector<int>{i, j});
                extend(i, j);
                extend(j, i);
                seen.emplace(i), seen.emplace(j);
            }
        }
        sort(begin(res), end(res));
        res.erase(unique(begin(res), end(res)), res.end());

        return dp[n] = res;
    }
};

int main() {
    vector<vector<int>> res;

    {
        Solution sol;
        res = sol.getFactors(2);
        cout << " ------------------- " << endl;
        for (auto& v: res) {
            copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    }

    {
        Solution sol;
        res = sol.getFactors(12);
        cout << " ------------------- " << endl;
        for (auto& v: res) {
            copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    }

    // Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]
    {
        Solution sol;
        res = sol.getFactors(32);
        cout << " ------------------- " << endl;
        for (auto& v: res) {
            copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    }

    {
        Solution sol;
        res = sol.getFactors(42);
        cout << " ------------------- " << endl;
        for (auto& v: res) {
            copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    }

    {
        Solution sol;
        res = sol.getFactors(72);
        cout << " ------------------- " << endl;
        for (auto& v: res) {
            copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    }

    {
        Solution sol;
        res = sol.getFactors(100);
        cout << " ------------------- " << endl;
        for (auto& v: res) {
            copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    }

    return 0;
}
