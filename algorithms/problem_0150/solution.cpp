/*
150. Evaluate Reverse Polish Notation  
Total Accepted: 64711 Total Submissions: 273096 Difficulty: Medium

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> numbers;
        for (const auto& t: tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/")
                numbers.emplace(stoll(t));
            else {
                auto a = numbers.top();
                numbers.pop();
                auto b = numbers.top();
                numbers.pop();
                long long result;
                if (t == "+")
                    result = a+b;
                else if (t == "-")
                    result = b-a;
                else if (t == "*")
                    result = a*b;
                else
                    result = b/a;
                numbers.emplace(result);
            }
        }
        if (numbers.size())
            return numbers.top();
        else
            return 0;
    }
};

int main()
{
    Solution sol;
    vector<string> tokens;
  
    tokens = {"0","3","/"};
    cout << "Result: " << sol.evalRPN(tokens) << endl;

    tokens = {"-128", "-128", "*", "-128", "*", "-128",
              "*",    "8",    "*", "-1",   "*"};
    cout << "Result: " << sol.evalRPN(tokens) << endl;

    return 0;
}

