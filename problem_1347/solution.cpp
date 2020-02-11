/*
1347. Minimum Number of Steps to Make Two Strings Anagram
Medium

Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.
Return the minimum number of steps to make t an anagram of s.
An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

Example 1:
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

Example 3:
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 

Example 4:
Input: s = "xxyyzz", t = "xxyyzz"
Output: 0

Example 5:
Input: s = "friend", t = "family"
Output: 4

Constraints:

1 <= s.length <= 50000
s.length == t.length
s and t contain lower-case English letters only.
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
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>count(26, 0);
        for (char ch: s)
            ++count[ch-'a'];
        for (char ch: t)
            --count[ch-'a'];
        int res = 0;
        for (int c: count)
            if (c > 0)
                res += c;
        return res;
    }
};

int main() {
    Solution sol;
    string s, t;

    // Output: 1
    s = "bab", t = "aba";

    // Output: 5
    s = "leetcode", t = "practice";

    // Output: 0
    //s = "anagram", t = "mangaar";

    // Output: 0
    //s = "xxyyzz", t = "xxyyzz";

    // Output: 4
    //s = "friend", t = "family";

    cout << sol.minSteps(s, t) << endl;
    
    return 0;
}
