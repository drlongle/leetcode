/*
224. Basic Calculator  
Total Accepted: 28007 Total Submissions: 125035 Difficulty: Hard

Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ),
the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

https://leetcode.com/problems/basic-calculator/
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

struct Item {
    enum Type {
        IS_NUMBER   = 0,
        IS_STRING   = 1,
        IS_OPERATOR = 2,
        IS_REVERSE_OPERATOR = 3
    };
    Item() { }
    Item(char op): m_type(IS_OPERATOR), m_operator(op) { }
    Item(int num): m_type(IS_NUMBER), m_number(num) { }
    Item(int begin, int end) :
        m_type(IS_STRING), m_indexes(make_pair(begin,end)) { }
    Type m_type;
    char m_operator;
    int  m_number;
    pair<int,int> m_indexes;
};

inline int find_op(string& s, int begin, int end, const string& ops,
    int& parens)
{
    int open_parenses = parens = 0;
    for (int i = begin; i <= end; ++i) {
        const char ch = s[i];
        if (ch == '(') {
            ++open_parenses;
            ++parens;
        } else if (ch ==')') {
            --open_parenses;
            ++parens;
        } else if (open_parenses == 0 && ops.find(ch) != string::npos)
            return i;
    }
    return -1;
}

inline int reverse_find_op(string& s, int begin, int end, const string& ops,
    int& parens)
{
    int open_parenses = parens = 0;
    for (int i = end; i >= begin; --i) {
        const char ch = s[i];
        if (ch == ')') {
            ++open_parenses;
            ++parens;
        } else if (ch =='(') {
            --open_parenses;
            ++parens;
        } else if (open_parenses == 0 && ops.find(ch) != string::npos)
            return i;
    }
    return -1;
}

inline int calc(char ch, int n1, int n2)
{
    switch (ch) {
        case '+': return n1+n2;
        case '-': return n1-n2;
        case '*': return n1*n2;
        case '/': return n1/n2;
    }
    return 0;
}

inline int string_to_int(string&s , int begin, int end) {
    long long result = 0;
    while (begin <= end && s[begin] == ' ') ++begin;
    while (begin <= end && s[end] == ' ') --end;
    while (begin <= end) {
        result = result*10 + s[begin]-'0';
        ++begin;
    }
    return result;
}

inline void skip_parenses(string&s , int& begin, int& end) {
    int open_parenses = 0;
    while (begin <= end) {
        if ( s[begin] != ' ' && s[begin] != '(')
            break;
        if (s[begin] == '(')
            ++open_parenses;
        ++begin;
    }
    while (begin <= end && open_parenses > 0) {
        if (s[end] != ' ' && s[end] != ')') break;
        if (s[end] == ')') --open_parenses;
        --end;
    }
}

inline bool is_number(string s, int begin, int end, int& result)
{
    while (begin <= end && s[begin] == ' ') ++begin;
    while (begin <= end && s[end] == ' ') --end;
    for ( result = 0; begin <= end; ++begin) {
        if (!isdigit(s[begin]))
            return false;
        result = result*10 + (s[begin]-'0');
    }
    return true;
}

class Solution {
public:
    int calculate(string s) {
        return calculate(s,0,s.size()-1);
    }

    inline int sweep(string& s, const string& ops, int begin, int end,
        int start_value, char start_op) {
        int result = start_value;
        char last_op = start_op;
        while (begin <= end)
        {
            int temp = 0;
            while (begin <= end && s[begin] == ' ') ++begin;
            for ( ; begin <= end && isdigit(s[begin]); ++begin)
                temp = 10*temp + (s[begin]-'0');
            result = calc(last_op, result, temp);
            while (begin <= end && s[begin] == ' ') ++begin;
            last_op = s[begin++];
        }
        return result;
    }

    inline bool parse(string& s, const string& ops, int begin, int end,
        vector<Item>& items) {
        int value, parens;
        bool result = false;
        while (begin <= end)
        {
            int index = reverse_find_op(s, begin, end, ops, parens);
            if (index < 0)
                break;
            result = true;
            if (parens == 0)
                items.emplace_back(string_to_int(s, index+1,end));
            else {
                int first = index+1, last = end;
                while (s[first] == '(' && s[last] == ')')
                    ++first, --last;
                items.emplace_back(first,last);
            }
            items.emplace_back(s[index]);
            end = index-1;
        }
        if (!result)
            return false;
        while (s[begin] == '(' && s[end] == ')')
            ++begin, --end;
        if (is_number(s,begin,end,value))
            items.emplace_back(value);
        else
            items.emplace_back(begin, end);
        return result;
    }

    int calculate(string& s, int begin, int end) {
        vector<Item> items;
        bool get_top = false;
        Item term1(begin,end), term2;
        while (items.size() > 0 || !get_top) {
            if (get_top) {
                term1 = items.back();
                items.pop_back();
                get_top = false;
            }
            if (term1.m_type == Item::IS_NUMBER) {
                Item op = items.back();
                items.pop_back();
                term2 = items.back();
                items.pop_back();

                if (term2.m_type == Item::IS_NUMBER) {
                    term1.m_number = (op.m_type == Item::IS_REVERSE_OPERATOR) ?
                        calc(op.m_operator, term2.m_number, term1.m_number) :
                        calc(op.m_operator, term1.m_number, term2.m_number);
                    if (items.empty()) return term1.m_number;
                    else term1.m_type = Item::IS_NUMBER;
                } else {
                    items.emplace_back(term1);
                    op.m_type = Item::IS_REVERSE_OPERATOR;
                    items.emplace_back(op);
                    term1 = term2;
                }
            } else {
                if (parse(s, "+-", term1.m_indexes.first,
                    term1.m_indexes.second, items))
                    get_top = true;
                else if (parse(s, "*/", term1.m_indexes.first,
                    term1.m_indexes.second, items))
                    get_top = true;
                else {
                    skip_parenses(s, term1.m_indexes.first,
                        term1.m_indexes.second);
                    if (is_number(s, term1.m_indexes.first,
                        term1.m_indexes.second, term1.m_number)) {
                        if (items.empty()) return term1.m_number;
                        else term1.m_type = Item::IS_NUMBER;
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    string s;
    s = "1 + 1";

    int result = sol.calculate(s);
    cout << "Result: " << result << endl;

    return 0;
}

