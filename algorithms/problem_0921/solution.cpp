/*
921. Minimum Add to Make Parentheses Valid
Medium

Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Example 1:
Input: "())"
Output: 1

Example 2:
Input: "((("
Output: 3

Example 3:
Input: "()"
Output: 0

Example 4:
Input: "()))(("
Output: 4

Note:

S.length <= 1000
S only consists of '(' and ')' characters.
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
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, cnt = 0;
        for (char ch: s) {
            if (ch == '(')
                ++cnt;
            else {
                --cnt;
                if (cnt < 0) {
                    ++res;
                    cnt = 0;
                }
            }
        }
        return res + cnt;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 1    
    s = "())";
    cout << sol.minAddToMakeValid(s) << endl;

    // Output: 3
    s = "(((";
    cout << sol.minAddToMakeValid(s) << endl;

    // Output: 0
    s = "()";
    cout << sol.minAddToMakeValid(s) << endl;

    // Output: 4
    s =  "()))((";
    cout << sol.minAddToMakeValid(s) << endl;
    
    return 0;
}
