/*
227. Basic Calculator II  
Total Accepted: 22484 Total Submissions: 89221 Difficulty: Medium

Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators
and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
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
    int calc(char ch, int n1, int n2)
    {
        switch(ch) {
        case '+':
            return n1+n2;
        case '-':
            return n1-n2;
        case '*':
            return n1*n2;
        case '/':
            return n1/n2;
        }
        return 0;
    }

    int find_op(string& s, int begin, int end, const string& ops) {
        for (int i = begin; i <= end; ++i) {
            if (ops.find(s[i]) != string::npos)
                return i;
        }
        return -1;
    }

    int string_to_int(string&s , int begin, int end) {
        int result = 0;
        while (begin <= end && s[begin] == ' ')
            ++begin;
        while (begin <= end && s[end] == ' ')
            --end;
        while (begin <= end) {
            result = result*10 + s[begin]-'0';
            ++begin;
        }

        return result;
    }

    /* Recursive method */
    int calculate(string& s, int begin, int end) {
        int op_index = find_op(s,begin,end, "+-");
        if (op_index >= 0) {
            int a = calculate(s,begin, op_index-1);
            int b = calculate(s,op_index+1,end);
            if (s[op_index] == '+')
                return a+b;
            else
                return a-b;
        }

        op_index = find_op(s,begin,end, "*/");
        if (op_index >= 0) {
            int a = calculate(s,begin, op_index-1);
            int b = calculate(s,op_index+1,end);
            if (s[op_index] == '*')
                return a*b;
            else
                return a/b;
        }

        int temp = string_to_int(s,begin,end);
        return temp;
    }

    int calculate(string s) {
        //return calculate(s,0,s.size()-1);
        vector<pair<int,char>> ops;
        ops.emplace_back(0, '+');
        int index = 0, end = s.size()-1;
        while (index <= end) {
            int new_index = find_op(s,index,end, "+-*/");
            int operand;
            char op;
            if (new_index < 0) {
                operand = string_to_int(s,index,end);
                op = '='; // pseudo operator for the last operand
            }
            else {
                operand = string_to_int(s,index,new_index-1);
                op = s[new_index];
            }

            char last_op = ops.back().second;
            if (last_op == '*') {
                ops.back().first *= operand;
                ops.back().second = op;
            } else if (last_op == '/') {
                ops.back().first /= operand;
                ops.back().second = op;
            } else
                ops.emplace_back(operand, op);
            if (new_index < 0)
                break;
            else
                index = new_index+1;
        }

        for (size_t i = 1; i < ops.size(); ++i) {
            int a = ops[i-1].first;
            int b = ops[i].first;
            ops[i].first = calc(ops[i-1].second,a,b);
        }

        return ops.back().first;
    }
};

int main()
{
    Solution sol;
    string input;
    input = "3+2*2";
    cout << "Result: " << sol.calculate(input) << endl;

    return 0;
}

