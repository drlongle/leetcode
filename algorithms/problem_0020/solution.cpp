/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> collected;
        for (int i = 0; i < static_cast<int>(s.size()); ++i)
        {
            char ch = s[i];
            if (collected.empty()) collected.emplace(ch);
            else if (ch == ')' && collected.top() == '(') collected.pop();
            else if (ch == '}' && collected.top() == '{') collected.pop();
            else if (ch == ']' && collected.top() == '[') collected.pop();
            else collected.emplace(ch);
        }
        if (collected.empty()) return true;
        else return false;
    }
};

int main()
{
    Solution sol;
    string s("{}");
    cout << "--> " << sol.isValid(s) << endl;

    return 0;
}

