/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings. 
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
    string longestCommonPrefix(vector<string>& strs)
    {
        int s_size = static_cast<int>(strs.size());
        if (s_size == 0)
            return string();
        string s = strs[0];
        for (int i = 1; i < s_size; ++i) {
            if (strs[i].size() < s.size())
                s = strs[i];
        }
        if (s.size() == 0)
            return string();

        string ret;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            string sub = s.substr(0, i+1);
            for (int j = 0; j < s_size; ++j) {
                if (strs[j].substr(0, i+1).compare(sub))
                    return ret;
            }
            ret = sub;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> strs{"a"};
    cout << sol.longestCommonPrefix(strs);
}
