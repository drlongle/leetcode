/*
680. Valid Palindrome II
Easy

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
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
    bool expand(const string& s, int i, int j, int skipleft, int skipright) {
        while (i >= 0 && j < sz) {
            if (s[i] != s[j]) {
                if (skipleft > 0) {
                    --i;
                    skipleft = 0;
                } else if (skipright > 0) {
                    ++j;
                    skipright = 0;
                } else
                    return false;
            } else
                --i, ++j;
        }
        return true;
    }
    int sz;
    bool validPalindrome(string s) {
        sz = s.size();
        if (!sz) return true;
        if (sz & 1) {
            if (expand(s, sz/2, sz/2, 0, 0) || expand(s, sz/2, sz/2+1, 1, 0) || expand(s, sz/2-1, sz/2, 0, 1))
                return true;
        } else {
            if (expand(s, sz/2-1, sz/2, 0, 0) || expand(s, sz/2-1, sz/2-1, 0, 1) || expand(s, sz/2, sz/2, 1, 0))
                return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: True
    s = "aba";

    // Output: True
    //s = "abca";

    // Output: False
    //s = "abc";
    
    // Output: False
    //s = "tebbem";
    
    cout << sol.validPalindrome(s) << endl;
    
    return 0;
}
