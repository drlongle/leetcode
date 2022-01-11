/*
151. Reverse Words in a String
Total Accepted: 104979 Total Submissions: 667664 Difficulty: Medium

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
*/

#include <algorithm>
#include <array>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    void skip_space(string& s)
    {
        int rindex = 0, windex = 0;
        int size = s.size();
        while (rindex < size)
        {
            while (rindex < size && s[rindex] == ' ')
                ++rindex;
            while (rindex < size && s[rindex] != ' ')
                s[windex++] = s[rindex++];
            if (rindex < size)
                s[windex++] = s[rindex++];
        }
        while (windex > 0 && s[windex-1] == ' ')
            --windex;
        s.resize(windex);
    }

    string reverseWords(string &s)
    {
        skip_space(s);

        int index = 0, size = s.size();
        if (!size) return "";
        while (index < size)
        {
            int next_index = index;
            while (next_index < size && s[next_index] != ' ')
                ++next_index;
            reverse(s.begin()+index, s.begin()+next_index);
            index = next_index+1;
        }
        reverse(s.begin(), s.end());

        return s;
    }
};

int main()
{
    Solution sol;
    string s;
    s = "  the   sky is  blue  ";
    sol.reverseWords(s);
    cout << "Result:" << s << endl;

    return 0;
}

