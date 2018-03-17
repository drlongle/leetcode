/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. For "(()", the longest valid parentheses substring is "()", which has length = 2. Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 

See https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
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

    inline int longestParens(const string& s, int start, bool& finish)
    {
        int s_size = static_cast<int>(s.size());
        int result = 0;
        int outstandleft = 0;
        finish = true;
        int end;
        for (end = start; end < s_size; ++end)
        {
            if (s[end] == '(') ++outstandleft;
            else
            {
                finish = false;
                if (!outstandleft)
                    break;
                else
                    --outstandleft;
            }
            if (!outstandleft)
                result = end - start +1;
        }

        return result;
    }

    int longestValidParentheses(string s)
    {
        int result = 0, temp;
        int i = 0, s_size = static_cast<int>(s.size());
        for (i = 0; i < s_size; ++i)
            if (s[i] == ')')
                break;
        if (i == s_size) return 0;
        i = 0;
        while (i < s_size)
        {
            bool finish = false;
            temp = longestParens(s, i, finish);
            if (temp > result)
                result = temp;
            if (finish)
                break;

            if (temp > 0) i += temp;
            else ++i;
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Expected: 22 
    string s(")(((((()())()()))()(()))(");
    cout << "Result: " << sol.longestValidParentheses(s) << endl;

    return 0;
}
