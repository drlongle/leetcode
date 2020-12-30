/*
248. Strobogrammatic Number III
Hard

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

Example:

Input: low = "50", high = "100"
Output: 3
Explanation: 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
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
    vector<string> strobos(int n) {
        if (n == 0)
            return vector<string>{""};
        if (n == 1)
            return {"0", "1", "8"};
        else {
            auto v = strobos(n - 2);
            vector<string> res;
            for (auto& s: v) {
                res.emplace_back('0' + s + '0');
                res.emplace_back('1' + s + '1');
                res.emplace_back('6' + s + '9');
                res.emplace_back('8' + s + '8');
                res.emplace_back('9' + s + '6');
            }
            return res;
        }
    }

    int strobogrammaticInRange(string low, string high) {
        int cnt = 0, lsz = low.size(), hsz = high.size();
        auto lambda = [&] (auto& s) {
            return (s.size() != low.size() || low <= s) && (s.size() != high.size() || s <= high);};
        for (int len = lsz; len <= hsz; ++len) {
            auto v = strobos(len);
            auto it = remove_if(begin(v), end(v), [] (auto& s) {return s.size() > 1 && s[0] == '0';});
            v.erase(it, v.end());
            if (len == lsz) {
                cnt += count_if(begin(v), end(v), lambda);
            } else if (len < hsz)
                cnt += v.size();
            else
                cnt += count_if(begin(v), end(v), lambda);
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    string low, high;

    // Output: 1
    low = "0", high = "0";
    cout << sol.strobogrammaticInRange(low, high) << endl;

    // Output: 3
    low = "50", high = "100";
    cout << sol.strobogrammaticInRange(low, high) << endl;

    // Output: 21
    low = "0", high = "1680";
    cout << sol.strobogrammaticInRange(low, high) << endl;

    return 0;
}
