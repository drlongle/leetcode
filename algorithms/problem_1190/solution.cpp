/*
1190. Reverse Substrings Between Each Pair of Parentheses
Medium

Given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any bracket.

Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "(u(love)i)"
Output: "iloveu"

Example 3:
Input: s = "(ed(et(oc))el)"
Output: "leetcode"

Example 4:
Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
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
    string reverseParentheses(string s) {
        stack<char> stak;
        for (auto ch: s) {
            if (ch == ')') {
                string temp;
                while (!stak.empty()) {
                    ch = stak.top();
                    stak.pop();
                    if (ch == '(')
                        break;
                    temp.push_back(ch);
                }
                for (auto ch: temp)
                    stak.push(ch);
            } else
                stak.push(ch);
        }

        string temp;
        while (!stak.empty()) {
            temp.push_back(stak.top());
            stak.pop();
        }
        reverse(begin(temp), end(temp));

        return temp;
    }
};


int main() {
    Solution sol;
    return 0;
}
