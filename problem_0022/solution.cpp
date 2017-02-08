/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
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
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        set<string> tempres;
        string s;
        generateParenthesis(n, n, s, tempres);

        for (const auto& st: tempres)
            ret.push_back(st);

        return ret;
    }

    void generateParenthesis(int left, int right, string& s,
        set<string>& tempres)
    {
        if (left == 0 && right == 0)
        {
            tempres.emplace(s);
            return;
        }

        if (left > 0)
        {
            s.push_back('(');
            generateParenthesis(left-1, right, s, tempres);
            s.pop_back();
        }

        if (right > left)
        {
            s.push_back(')');
            generateParenthesis(left, right-1, s, tempres);
            s.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Input n: "; 
    cin >> n;
    vector<string> ret = sol.generateParenthesis(n);
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}

