/*
91. Decode Ways
Total Accepted: 72667 Total Submissions: 408775 Difficulty: Medium

A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.  
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
    int numDecodings(string s) {
        int ssize = s.size();
        if (!ssize) return 0;
        vector<int> count(ssize, 0);

        for (int i = ssize-1; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                if (i == 0 || s[i-1] == '0' || s[i-1] > '2')
                    return 0;
                else
                    count[i] = 0;
            }
            else
                count[i] = (i == ssize-1) ? 1 : count[i+1];
            if (((s[i] == '1') || (s[i] == '2'&& s[i+1] <= '6')) && i+1 < ssize)
                count[i] += (i == ssize-2) ? 1 : count[i+2];
        }

        return count[0];
    }
};

int main()
{
    Solution sol;
    string s;

    // Expected: 3
    s = "1201234";
    cout << "Result: " << sol.numDecodings(s) << endl;

    // Expected: 2
    s = "12";
    cout << "Input: ";
    cin >> s;
    cout << "Result: " << sol.numDecodings(s) << endl;

    return 0;
}

