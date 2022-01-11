/*
424. Longest Repeating Character Replacement

    Difficulty: Medium

Given a string that consists of only uppercase English letters, you can replace
any letter in the string with another letter at most k times. Find the length
of a longest substring containing all repeating letters you can get after
performing the above operations.

Note:
Both the string's length and k will not exceed 10^4.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
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
    int characterReplacement(string s, int k) {
        unordered_map<char, vector<pair<int, int> > > positions;
        int size = static_cast<int>(s.size());
        int i = 0;
        while (i < size)
        {
            int begin = i, end = i+1;
            char ch = s[i];
            while (end < size && s[end] == ch)
                ++end;
            i = end;
            positions[ch].push_back(make_pair(begin, end));
        }

        int res = 0;
        for (auto& pos: positions)
        {
            vector<pair<int,int> >& ranges = pos.second;
            int rsize = ranges.size();
            for (int i = 0; i < rsize; ++i)
            {
                int temp = ranges[i].second - ranges[i].first;
                int num = k;
                for (int j = i+1; j < rsize; ++j)
                {
                    int dist = ranges[j].first - ranges[j-1].second;
                    if (num < dist)
                        break;
                    num -= dist;
                    temp += ranges[j].second - ranges[j].first + dist;
                }

                if (num > 0)
                {
                    temp += min(num, ranges[i].first);
                    num -= ranges[i].first;
                    if (num > 0)
                        temp += min(num, size - ranges[rsize-1].second);
                }
                if (temp > res)
                    res = temp;
            }
        }

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string s;
    int k;

    // Expected: 4
    s = "ABAB", k = 2;
    cout << "Result: " << sol.characterReplacement(s, k) << endl;
    return 0;
}

