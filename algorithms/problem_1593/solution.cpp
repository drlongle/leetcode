/*
1593. Split a String Into the Max Number of Unique Substrings
Medium

Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

Example 2:
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].

Example 3:
Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.

Constraints:
1 <= s.length <= 16
s contains only lower case English letters.
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

using namespace std;

class Solution {
public:

    std::size_t n, res;
    unordered_set<string> table;

    void backtrack(string& s, size_t index) {
        if (index == n) {
            res = max(res, table.size());
            return;
        }

        for (size_t i = index; i < n; ++i) {
            string sub = s.substr(index, i-index+1);
            auto [it, inserted] = table.emplace(sub);
            if (inserted) {
                backtrack(s, i+1);
                table.erase(it);
            }
        }
    }

    int maxUniqueSplit(string s) {
        res = 0;
        n = s.size();
        backtrack(s, 0);

        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 5
    s = "ababccc";
    cout << sol.maxUniqueSplit(s) << endl;

    // Output: 2
    s = "aba";
    cout << sol.maxUniqueSplit(s) << endl;

    // Output: 1
    s = "aa";
    cout << sol.maxUniqueSplit(s) << endl;

    return 0;
}
