/*
1542. Find Longest Awesome Substring
Hard

Given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps
in order to make it palindrome.

Return the length of the maximum length awesome substring of s.

Example 1:
Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.

Example 2:
Input: s = "12345678"
Output: 1

Example 3:
Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.

Example 4:
Input: s = "00"
Output: 2

Constraints:
1 <= s.length <= 10^5
s consists only of digits.
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
    int longestAwesome(string& s) {
        using BS = bitset<10>;
        unordered_map<BS, int> pos;
        vector<int> cnt(10, 0);
        int res = 1, sz = s.size();
        BS bs;
        for (int i = 0; i < sz; ++i) {
            int index = s[i] - '0';
            bs.flip(index);
            if (bs.count() <= 1)
                res = i + 1;
            else {
                for (int j = 0; j < 10; ++j) {
                    auto nbs = bs;
                    nbs.flip(j);
                    auto it = pos.find(nbs);
                    if (it != pos.end()) {
                        res = max(res, i - it->second);
                    }
                }
            }
            pos.emplace(bs, i);
        }

        return res;
    }
};

int main() {
    string s;

    // Output: 5
    {
        Solution sol;
        s = "3242415";
        cout << sol.longestAwesome(s) << endl;
    }

    // Output: 1
    {
        Solution sol;
        s = "12345678";
        cout << sol.longestAwesome(s) << endl;
    }

    // Output: 6
    {
        Solution sol;
        s = "213123";
        cout << sol.longestAwesome(s) << endl;
    }

    // Output: 2
    {
        Solution sol;
        s = "00";
        cout << sol.longestAwesome(s) << endl;
    }

    // Output: 5
    {
        Solution sol;
        s = "10120";
        cout << sol.longestAwesome(s) << endl;
    }

    // Output: 10
    {
        Solution sol;
        s = "1234512345";
        cout << sol.longestAwesome(s) << endl;
    }

    // Output: 3
    {
        Solution sol;
        s = "51224";
        cout << sol.longestAwesome(s) << endl;
    }

    return 0;
}
