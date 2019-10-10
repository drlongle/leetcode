/*
1216. Valid Palindrome III
Hard

Given a string s and an integer k, find out if the given string is a K-Palindrome or not.
A string is K-Palindrome if it can be transformed into a palindrome by removing at most k
characters from it. 

Example 1:
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
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
    bool isValidPalindrome(string s, int k) {
        if (s == string(s.rbegin(), s.rend())) {  // optional, to optimize special case
            return true;
        }
        
        vector<vector<int>> dp(2, vector<int>(s.size(), 1));
        for (int i = s.length() - 2; i >= 0; --i) {
            for (int j = i + 1; j < s.length(); ++j) {
                if (s[i] == s[j]) {
                    dp[i % 2][j] = (i + 1 <= j - 1) ? 2 + dp[(i + 1) % 2][j - 1] : 2;
                } else {
                    dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return s.length() <= k +dp[0][s.length() - 1];
    }
};


int main() {
    Solution sol;
    string s;
    int k;

    // Output: true
    s = "abcdeca", k = 2;

    // 19 / 49 test cases passed.
    s = "cccabbcccbdcaaabbcdbddccaddccbabbabdbaaabbbbdcabacccbbdbbbdbdcdd";
    k = 1;

    // 24 / 49 test cases passed.
    // Expected: false
    s = "bacabaaa", k = 2;

    // Expected: false
    s = "dadbadbdbcdacdbbccbcdbcbddddbaaabacdadddabdcbdbbdccbbddcbaddcbadadbdabcbaabcaacaccaddbbdacdcdacbbcab";
    k = 1;
    
    cout << "Result: " << boolalpha << sol.isValidPalindrome(s, k) << endl;
    
    return 0;
}
