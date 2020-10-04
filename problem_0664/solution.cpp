/*
664. Strange Printer
Hard

There is a strange printer with the following two special requirements:
- The printer can only print a sequence of the same character each time.
- At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.

Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

Example 1:
Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:
Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

Hint: Length of the given string will not exceed 100.
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
    vector<vector<int>> dp;
    int count(string& s, int begin, int end) {
        int diff = end - begin;
        if (diff < 0)
            return 0;
        if (diff == 0)
            return 1;
        int& res = dp[begin][end];
        if (res > 0)
            return res;
        ostringstream oss;
        char first = s[begin], last = s[end];
        int cnt1 = 1;
        int i = begin, prev = end + 1;
        while (i <= end) {
            if (s[i] == first) {
                cnt1 += count(s, prev, i-1);
                while (i <= end && s[i] == first)
                    ++i;
                prev = i;
            } else
                ++i;
        }
        if (first != last)
            cnt1 += count(s, prev, end);

        i = begin;
        while (i <= end && s[i] == first)
            ++i;
        int j = end;
        while (j >= i && s[j] == first)
            --j;
        int cnt4 = count(s, i, j) + (first == last ? 1 : 2);

        int cnt2 = 1;
        i = end, prev = end;
        while (i >= begin) {
            if (s[i] == last) {
                cnt2 += count(s, i+1, prev);
                while (i >= begin && s[i] == last)
                    --i;
                prev = i;
            } else
                --i;
        }
        if (first != last)
            cnt2 += count(s, begin, prev);

        int cnt3 = end-begin+1;
        for (int i = begin; i < end; ++i) {
            int t1 = count(s, begin, i);
            int t2 = count(s, i+1, end);
            if (first == s[i+1] && t2 == 1) {
                cnt3 = min(cnt3, t1);
            } else if (last == s[i] && t1 == 1)
                cnt3 = min(cnt3, t2);
            else
                cnt3 = min(cnt3, t1 + t2);
        }
        res = min({cnt1, cnt2, cnt3, cnt4});
        return res;
    }

    int strangePrinter(string s) {
        int sz = s.size();
        dp.resize(sz, vector<int>(sz, -1));

        return count(s, 0, sz-1);
    }
};

int main() {
    string s;

    // Output: 2
    {
        Solution sol;
        s = "aaabbb";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 2
    {
        Solution sol;
        s = "aba";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 3
    {
        Solution sol;
        s = "aaabbbaaabbb";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 5
    {
        Solution sol;
        s = "abcabc";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 7
    {
        Solution sol;
        s = "abcabcabc";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 19
    {
        Solution sol;
        s = "baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 15
    {
        Solution sol;
        s = "dddccbdbababaddcbcaabdbdddcccddbbaabddb";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 13
    {
        Solution sol;
        s = "daacbadbdcbdbdaadbcadadccd";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 14
    {
        Solution sol;
        s = "bdaacbadbdcbdbdaadbcadadccd";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 17
    {
        Solution sol;
        s = "abdaacbadbdcbdbdaadbcadadccdaaadcb";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 12
    {
        Solution sol;
        s = "bdbababaddcbcaabdbdddcccddbbaab";
        cout << sol.strangePrinter(s) << endl;
    }

    // Output: 21
    {
        Solution sol;
        s = "dcddbaccadbccddabbcdcdbddbaabcbbdaccacbddcdabdb";
        cout << sol.strangePrinter(s) << endl;
    }

    return 0;
}
