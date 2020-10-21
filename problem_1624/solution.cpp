/*
1624. Largest Substring Between Two Equal Characters
Easy

Given a string s, return the length of the longest substring between two equal characters, excluding the
two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.

Example 2:
Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".

Example 3:
Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.

Example 4:
Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".

Constraints:
1 <= s.length <= 300
s contains only lowercase English letters.
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
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1, sz = s.size();
        vector<int> cnt(26, -1);
        for (int i = 0; i < sz; ++i) {
            int index = s[i] - 'a';
            if (cnt[index] >= 0)
                res = max(res, i - cnt[index] - 1);
            else
                cnt[index] = i;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    s = "aa";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    s = "abca";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    s = "cabbac";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    s = "mgntdygtxrvxjnwksqhxuxtrv";
    cout << sol.maxLengthBetweenEqualCharacters(s) << endl;

    return 0;
}
