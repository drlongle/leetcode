/*
1106. Parsing A Boolean Expression
Hard

Return the result of evaluating a given boolean expression, represented as a string.
An expression can either be:
"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...

Example 1:
Input: expression = "!(f)"
Output: true

Example 2:
Input: expression = "|(f,t)"
Output: true

Example 3:
Input: expression = "&(t,f)"
Output: false

Example 4:
Input: expression = "|(&(t,f,t),!(t))"
Output: false
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

    char eval(stack<char>& s) {
        vector<char> elems;
        char ch;
        while (!s.empty()) {
            ch = s.top();
            s.pop();
            if (ch == '(') {
                ch = s.top();
                s.pop();
                elems.emplace_back(ch);
                break;
            } else
                elems.emplace_back(ch);
        }
        char token = elems.back();
        elems.resize(elems.size() - 1);
        switch (token) {
        case '!':
            elems[0] = (elems[0] == 't') ? 'f' : 't';
            break;
        case '&':
            elems[0] = all_of(begin(elems), end(elems), [](const char& ch) {return ch == 't';}) ? 't' : 'f';
            break;
        case '|':
            elems[0] = any_of(begin(elems), end(elems), [](const char& ch) {return ch == 't';}) ? 't' : 'f';
            break;
        }

        return elems[0];
    }

    bool parseBoolExpr(string expression) {
        stack<char> s;
        for (char ch: expression) {
            if (ch == ')')
                ch = eval(s);
            else if (ch == ',')
                continue;
            s.emplace(ch);
        }

        return s.top() == 't' ? true : false;
    }
};

int main() {
    Solution sol;
    vector<pair<string, bool>> expr {
        {"&(t,t,t)", true},
        {"f", false},
        {"!(f)", false},
        {"!(!(f))", false},
        {"!(!(!(f)))", false},
        {"!(!(!(!(f))))", false},
        {"t", true},
        {"!(t)", true},
        {"!(!(t))", true},
        {"!(!(!(t)))", true},
        {"!(!(!(!(t))))", true},
        {"|(f,t)", true},
        {"&(t,f)", false},
        {"|(&(t,f,t),!(t))", false}
    };

    for (auto& p: expr) {
        cout << p.first << " -> " << boolalpha << sol.parseBoolExpr(p.first) << ", expected: " << p.second << endl;
    }

    return 0;
}

