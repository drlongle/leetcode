/*
678. Valid Parenthesis String
Medium

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
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

    bool checkValidString(string s) {
        stack<char> sta;
        for (char ch: s) {
            if (ch == ')') {
                if (sta.empty())
                    return false;
                else {
                    stack<char> helper;
                    while (!sta.empty() && sta.top() == '*') {
                        helper.push('*');
                        sta.pop();
                    }
                    if (!sta.empty())
                        sta.pop();
                    else
                        helper.pop();
                    while (!helper.empty()) {
                        sta.push('*');
                        helper.pop();
                    }

                }
            } else
                sta.push(ch);
        }

        stack<char> helper;
        while (!sta.empty()) {
            if (sta.top() == '(') {
                if (helper.empty())
                    return false;
                sta.pop();
                helper.pop();
            } else {
                sta.pop();
                helper.push('*');
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: True
    s = "()";
    cout << boolalpha << sol.checkValidString(s) << endl;

    // Output: True
    s = "(*)";
    cout << boolalpha << sol.checkValidString(s) << endl;
    
    // Output: True
    s = "(*))";
    cout << boolalpha << sol.checkValidString(s) << endl;

    // Expected: false
    s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
    cout << boolalpha << sol.checkValidString(s) << endl;
    
    // Expected: false?
    s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    cout << boolalpha << sol.checkValidString(s) << endl;
        
    return 0;
}
