/*
1397. Find All Good Strings
Hard

Given the strings s1 and s2 of size n, and the string evil. Return the number of good strings.

A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.

Example 1:
Input: n = 2, s1 = "aa", s2 = "da", evil = "b"
Output: 51 
Explanation: There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da". 

Example 2:
Input: n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
Output: 0 
Explanation: All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.

Example 3:
Input: n = 2, s1 = "gx", s2 = "gz", evil = "x"
Output: 2

Constraints:
s1.length == n
s2.length == n
1 <= n <= 500
1 <= evil.length <= 50
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
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
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
    int dp[501][51][2][2] = {};
    int dfs(const string &s1, const string &s2, const string &evil, int sp, int ep, bool l1, bool l2, const vector<int> &kmp) {
        if (ep == evil.size())
            return 0;
        if (sp == s1.size())
            return 1;
        if (!dp[sp][ep][l1][l2]) {
            for (char ch = (l1 ? s1[sp] : 'a'); ch <= (l2 ? s2[sp] : 'z'); ++ch) {
                auto n_ep = ep;
                while (n_ep > 0 && ch != evil[n_ep])
                    n_ep = kmp[n_ep - 1];
                dp[sp][ep][l1][l2] = (dp[sp][ep][l1][l2] + 
                                      dfs(s1, s2, evil, sp + 1, ch == evil[n_ep] ? n_ep + 1 : 0, 
                                          l1 & (ch == s1[sp]), l2 & (ch == s2[sp]), kmp)) % 1000000007;
            }
        }
        return dp[sp][ep][l1][l2];
    }
    
    int findGoodStrings(int n, string &s1, string &s2, string &evil) {
        vector<int> kmp(evil.size());
        for (auto j = 0, i = 1; i < kmp.size(); ++i) {
            if (evil[i] == evil[j])
                kmp[i] = ++j;
            else if (j > 0) {
                j = kmp[j - 1];
                --i;
            }
        }
        return dfs(s1, s2, evil, 0, 0, true, true, kmp);
    }
};

int main() {
    Solution sol;
    string s1, s2, evil;
    int n;

    // Output: 51
    n = 2, s1 = "aa", s2 = "da", evil = "b";
    //cout << sol.findGoodStrings(n, s1, s2, evil) << endl;
    
    // Output: 0
    n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet";
    //cout << sol.findGoodStrings(n, s1, s2, evil) << endl;
    
    // Output: 2
    n = 2, s1 = "gx", s2 = "gz", evil = "x";
    //cout << sol.findGoodStrings(n, s1, s2, evil) << endl;

    // Output: 0
    n = 8, s1 = "leetaaaa", s2 = "leetyyyy", evil = "leet";
    //cout << sol.findGoodStrings(n, s1, s2, evil) << endl;

    // Output: 4357
    n = 3, s1 = "szc", s2 = "zyi", evil = "p";
    //cout << sol.findGoodStrings(n, s1, s2, evil) << endl;

    // Expected: 500543753
    n = 8, s1 = "pzdanyao", s2 = "wgpmtywi", evil = "sdka";
    cout << sol.findGoodStrings(n, s1, s2, evil) << endl;
    
    return 0;
}
