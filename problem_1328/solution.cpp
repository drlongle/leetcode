/*
1328. Break a Palindrome
Medium

Given a palindromic string palindrome, replace exactly one character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that isn't a palindrome.
After doing so, return the final string.  If there is no way to do so, return the empty string.

Example 1:
Input: palindrome = "abccba"
Output: "aaccba"

Example 2:
Input: palindrome = "a"
Output: ""

Constraints:
1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters
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
    string breakPalindrome(string palindrome) {
        string& s(palindrome);
        string res;
        int sz = s.size();
        if (sz == 1)
            return res;
        for (int begin = 0, end = sz-1; begin < end; ++begin, --end) {
            char ch = s[begin];
            s[begin] = (s[begin] == 'a') ? 'b' : 'a';
            if (res.empty())
                res = s;
            else
                res = min(s, res);
            s[begin] = ch;
            ch = s[end];
            s[end] = (s[end] == 'a') ? 'b' : 'a';
            res = min(s, res);
            s[end] = ch;
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string palindrome;

    // Output: "aaccba"
    palindrome = "abccba";

    // Output: ""
    //palindrome = "a";

    palindrome = "aa";
    
    cout << "Result: " << sol.breakPalindrome(palindrome) << endl;
    
    return 0;
}
