/*
1400. Construct K Palindrome Strings
Medium

Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

Example 1:
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Example 2:
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Example 3:
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

Example 4:
Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.

Example 5:
Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.

Constraints:
1 <= s.length <= 10^5
All characters in s are lower-case English letters.
1 <= k <= 10^5
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
    bool canConstruct(string s, int k) {
        int sz = s.size();
        if (sz < k)
            return false;
        unordered_map<char, int> cnt;
        for (char ch: s)
            ++cnt[ch];
        int odds = count_if(begin(cnt), end(cnt), [&] (auto& p) {return p.second % 2 == 1;});

        return odds  <= k;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // Output: false
    s = "true", k = 3;
    //cout << boolalpha <<  sol.canConstruct(s, k) << endl;
    
    // Output: true
    s = "annabelle", k = 2;
    //cout << boolalpha << sol.canConstruct(s, k) << endl;

    // Output: false
    s = "leetcode", k = 3;
    //cout << boolalpha <<  sol.canConstruct(s, k) << endl;

    s = "true", k = 4;
    //cout << boolalpha <<  sol.canConstruct(s, k) << endl;
    
    // Output: true
    s = "yzyzyzyzyzyzyzy", k = 2;
    //cout << boolalpha <<  sol.canConstruct(s, k) << endl;
    
    // Output: false;
    s = "cr", k = 7;
    //cout << boolalpha <<  sol.canConstruct(s, k) << endl;

    // Output: false;
    s = "abcdefghijklmnopqrstuvwxyz", k = 25;
    cout << boolalpha <<  sol.canConstruct(s, k) << endl;

    // Expected: false
    s = "xiaomi", k = 3;
    cout << boolalpha <<  sol.canConstruct(s, k) << endl;
    
    return 0;
}
