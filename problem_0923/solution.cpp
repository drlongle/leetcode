/*
923. 3Sum With Multiplicity
Medium

Given an integer array arr, and an integer target, return the number of tuples i, j, k such that
i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.

Example 1:
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation:
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Example 2:
Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation:
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.

Constraints:
3 <= arr.length <= 3000
0 <= arr[i] <= 100
0 <= target <= 300
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

    map<pair<int, int>, int> facts;

    static constexpr int MOD = 1000000007;

    int choose(int n, int k) {
        if (n == 0 || k == 0 || n == k)
            return 1;
        auto key = make_pair(n, k);
        auto it = facts.find(key);
        if (it != facts.end())
            return it->second;

        int res = (choose(n-1, k) + choose(n-1, k-1)) % MOD;
        facts.emplace(key, res);
        return res;
    }

    int threeSumMulti(vector<int>& arr, int target) {
        map<int, int> cnt;
        for (int n: arr)
            ++cnt[n];

        int res = 0;
        for (auto it1 = cnt.begin(); it1 != cnt.end(); ++it1) {
            for (auto it2 = it1->second > 1 ? it1 : std::next(it1); it2 != cnt.end(); ++it2) {
                int i = it1->first, k = it2->first;
                int u = it1->second, v = it2->second;
                int key = target - i - k;
                if (key < k)
                    continue;
                auto it = cnt.find(key);
                if (it == cnt.end())
                    continue;
                int l = it->first, w = it->second;
                if (i == k && k == l) {
                    if (u >= 3)
                        res = (res + choose(u, 3)) % MOD;
                }
                else if (i == k && k != l) {
                    if (u >= 2)
                        res = (res + choose(u, 2) * w) % MOD;
                }
                else if (l == k) {
                    if (w >= 2)
                        res = (res + u * choose(w, 2)) % MOD;
                } else
                    res = (res + u * v * w) % MOD;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int target;

    // Output: 20
    arr = {1,1,2,2,3,3,4,4,5,5}, target = 8;
    cout << sol.threeSumMulti(arr, target) << endl;

    // Output: 12
    arr = {1,1,2,2,2,2}, target = 5;
    cout << sol.threeSumMulti(arr, target) << endl;

    // Output: 2
    arr = {1,2,3,3,1}, target = 5;
    cout << sol.threeSumMulti(arr, target) << endl;

    return 0;
}
