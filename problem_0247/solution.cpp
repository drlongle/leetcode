/*
247. Strobogrammatic Number II
Medium

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
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
    unordered_map<char, char> strobos {
            {'0','0' },
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}};

    vector<string> res;

    void DFS(string& s, int left, int right) {
        if (left == 0 && 0 == right) {
            for (char ch: {'0', '1', '8'}) {
                res.emplace_back(string(1, ch));
            }
        } else if (left == 0 && left != right) {
            for (char ch: {'1', '6', '8', '9'}) {
                s[left] = ch;
                s[right] = strobos[ch];
                if (right - left > 1) {
                    DFS(s, left + 1, right - 1);
                } else
                    res.emplace_back(s);
            }
        } else {
            for (auto& p: strobos) {
                if (left == right && (p.first == '6' || p.first == '9'))
                    continue;
                s[left] = p.first;
                s[right] = p.second;
                if (right - left > 1) {
                    DFS(s, left + 1, right - 1);
                } else
                    res.emplace_back(s);
            }
        }
    }

    vector<string> findStrobogrammatic(int n) {
        res.clear();
        string r(n, ' ');
        DFS(r, 0, n-1);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> res;
    int n;

    // ["1","9","8","6"]
    n = 1;
    res = sol.findStrobogrammatic(n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // ["11","69","88","96"]
    n = 2;
    res = sol.findStrobogrammatic(n);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
