/*
1898. Maximum Number of Removable Characters
Medium

You are given two strings s and p where p is a subsequence of s. You are also given a distinct 0-indexed
integer array removable containing a subset of indices of s (s is also 0-indexed).

You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters from s using
the first k indices in removable, p is still a subsequence of s. More formally, you will mark the character at
s[removable[i]] for each 0 <= i < k, then remove all marked characters and check if p is still a subsequence.

Return the maximum k you can choose such that p is still a subsequence of s after the removals.

A subsequence of a string is a new string generated from the original string with some characters (can be none)
deleted without changing the relative order of the remaining characters.

Example 1:
Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
Explanation: After removing the characters at indices 3 and 1, "abcacb" becomes "accb".
"ab" is a subsequence of "accb".
If we remove the characters at indices 3, 1, and 0, "abcacb" becomes "ccb", and "ab" is no longer a subsequence.
Hence, the maximum k is 2.

Example 2:
Input: s = "abcbddddd", p = "abcd", removable = [3,2,1,4,5,6]
Output: 1
Explanation: After removing the character at index 3, "abcbddddd" becomes "abcddddd".
"abcd" is a subsequence of "abcddddd".

Example 3:
Input: s = "abcab", p = "abc", removable = [0,1,2,3,4]
Output: 0
Explanation: If you remove the first index in the array removable, "abc" is no longer a subsequence.

Constraints:
1 <= p.length <= s.length <= 10^5
0 <= removable.length < s.length
0 <= removable[i] < s.length
p is a subsequence of s.
s and p both consist of lowercase English letters.
The elements in removable are distinct.
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
    vector<vector<int>> pos;
    unordered_set<int> striked;

    bool check(string s, string p, vector<int>& removable, int k) {
        for (int i = striked.size(); i < k; ++i)
            striked.insert(removable[i]);
        while (striked.size() > k ) {
            int i = removable[striked.size() - 1];
            striked.erase(i);
        }

        int index = 0;
        for (char c: p) {
            auto& v = pos[c - 'a'];
            while (true) {
                auto it = lower_bound(begin(v), end(v), index);
                if (it == end(v))
                    return false;
                index = *it;
                bool skipped = striked.count(index);
                ++index;
                if (skipped)
                    continue;
                else
                    break;
            }
        }
        return true;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        pos.resize(26);
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int lo = 0, hi = removable.size(), ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(s, p, removable, mid)) {
                lo = mid + 1;
                ans = mid;
            } else
                hi = mid - 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s, p;
    vector<int> removable;

    // Output: 2
    {
        Solution sol;
        s = "abcacb", p = "ab", removable = {3,1,0};
        cout << sol.maximumRemovals(s, p, removable) << endl;
    }


    // Output: 1
    {
        Solution sol;
        s = "abcbddddd", p = "abcd", removable = {3, 2, 1, 4, 5, 6};
        cout << sol.maximumRemovals(s, p, removable) << endl;
    }

    // Output: 0
    {
        Solution sol;
        s = "abcab", p = "abc", removable = {0, 1, 2, 3, 4};
        cout << sol.maximumRemovals(s, p, removable) << endl;
    }

    return 0;
}
