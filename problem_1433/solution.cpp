/*
1433. Check If a String Can Break Another String
Medium

Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa (in other words s2 can break s1).

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

Example 1:
Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".

Example 2:
Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.

Example 3:
Input: s1 = "leetcodee", s2 = "interview"
Output: true

Constraints:
s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    bool can_break(string& s, map<char, int>& cnt) {
        bool can_break = true;
        for (char ch: s) {
            auto it = cnt.lower_bound(ch);
            if (it == cnt.end()) {
                return false;
            }
            if (--(it->second) == 0)
                cnt.erase(it);
        }
        return can_break;
    }

    bool checkIfCanBreak(string s1, string s2) {
        map<char, int> cnt1, cnt2;
        for (char ch: s1)
            ++cnt1[ch];
        for (char ch: s2)
            ++cnt2[ch];
        if (can_break(s1, cnt2))
            return true;

        return can_break(s2, cnt1);
    }
};

int main() {
    Solution sol;
    string s1, s2;

    s1 = "abc", s2 = "xya";
    cout << boolalpha << sol.checkIfCanBreak(s1, s2) << endl;

    s1 = "abe", s2 = "acd";
    cout <<  boolalpha << sol.checkIfCanBreak(s1, s2) << endl;

    s1 = "leetcodee", s2 = "interview";
    cout <<  boolalpha << sol.checkIfCanBreak(s1, s2) << endl;

    return 0;
}
