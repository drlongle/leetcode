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
        int n = s.length();
        vector<int> cnt(n+1, 0);
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch > '0')
                cnt[i+1] = (i > 0) ? cnt[i] : 1;
            if (i >= 1) {
                if (s[i-1] == '1' || (s[i-1] == '2' && ch <= '6'))
                    cnt[i+1] += cnt[i-1];
            }
        }
        return cnt[n];
    }
};

int main()
{
    Solution sol;
    string s;

    // Expected: 2
    s = "12";
    cout << "Input: ";
    cin >> s;
    cout << "Result: " << sol.numDecodings(s) << endl;

    return 0;
}

