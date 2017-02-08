/*
58. Length of Last Word
Total Accepted: 96578 Total Submissions: 326246 Difficulty: Easy

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string. If the last word does not exist, return 0. Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size()-1;
        while (end >= 0 && s[end] == ' ')
            --end;
        if (end < 0) return 0;
        int begin = end - 1;
        while (begin >= 0 && s[begin] != ' ')
            --begin;
        return end-begin;
    }
};

int main()
{
    Solution sol;
    string s;
    int res;

    s = "Hello World";
    res = sol.lengthOfLastWord(s);
    cout << "Result: " << res << endl;
    return 0;
}

