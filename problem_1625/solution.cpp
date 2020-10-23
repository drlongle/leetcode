/*
1625. Lexicographically Smallest String After Applying Operations
Medium

You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and
a = 5, s becomes "3951". Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes
"6345". Return the lexicographically smallest string you can obtain by applying the above operations any number
of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position
where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter
in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at
the third letter, and '5' comes before '9'.

Example 1:
Input: s = "5525", a = 9, b = 2
Output: "2050"
There is no way to obtain a string that is lexicographically smaller then "2050".

Example 2:
Input: s = "74", a = 5, b = 1
Output: "24"
There is no way to obtain a string that is lexicographically smaller then "24".

Example 3:
Input: s = "0011", a = 4, b = 2
Output: "0011"
Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".

Example 4:
Input: s = "43987654", a = 7, b = 3
Output: "00553311"

Constraints:
2 <= s.length <= 100
s.length is even.
s consists of digits from 0 to 9 only.
1 <= a <= 9
1 <= b <= s.length - 1
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

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        q.emplace(s);
        visited.emplace(s);
        string res(s);
        int sz = s.size();
        while (!q.empty()) {
            s = q.front();
            if (s < res)
                res = s;

            for (int k = 0; k < sz; k += b) {
                string t(s);
                reverse(begin(t), end(t));
                reverse(t.begin(), t.begin() + k);
                reverse(t.begin()+k, t.end());
                auto [it, inserted] = visited.emplace(t);
                if (inserted)
                    q.emplace(t);
            }

            for (int d = a; d <= 9; d += a) {
                string t(s);
                for (int i = 1; i < sz; i += 2) {
                    t[i] = '0' + (((t[i] - '0') + d) % 10);
                }
                auto [it, inserted] = visited.emplace(t);
                if (inserted)
                    q.emplace(t);
            }

            q.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;
    int a, b;

    // Output: "2050"
    s = "5525", a = 9, b = 2;
    cout << sol.findLexSmallestString(s, a, b) << endl;

    // Output: "24"
    s = "74", a = 5, b = 1;
    cout << sol.findLexSmallestString(s, a, b) << endl;

    // Output: "0011"
    s = "0011", a = 4, b = 2;
    cout << sol.findLexSmallestString(s, a, b) << endl;

    // Output: "00553311"
    s = "43987654", a = 7, b = 3;
    cout << sol.findLexSmallestString(s, a, b) << endl;

    return 0;
}
