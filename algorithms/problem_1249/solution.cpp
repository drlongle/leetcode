/*
1249. Minimum Remove to Make Valid Parentheses
Medium

Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')',
in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:
- It is the empty string, contains only lowercase characters, or
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

Example 4:
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

Constraints:
  1 <= s.length <= 10^5
  s[i] is one of  '(' , ')' and lowercase English letters.
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
    string minRemoveToMakeValid(string s) {
        ostringstream oss;
        stack<int> pos;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
                case '(':
                    s[i] = -1;
                    pos.emplace(i);
                    break;
                case ')':
                    if (pos.empty())
                        s[i] = -1;
                    else {
                        s[pos.top()] = '(';
                        pos.pop();
                    }
                    break;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != -1)
                oss << s[i];
        }
        return oss.str();
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "lee(t(c)o)de"
    s = "lee(t(c)o)de)";

    // Output: "ab(c)d"
    //s = "a)b(c)d";

    // Output: ""
    //s = "))((";

    // Output: "a(b(c)d)"
    //s = "(a(b(c)d)";
    
    cout << "Result: " << sol.minRemoveToMakeValid(s) << endl;
    
    return 0;
}
