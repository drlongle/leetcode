/*
1180. Count Substrings with Only One Distinct Letter
Easy

Given a string S, return the number of substrings that have only one distinct letter.

Example 1:
Input: S = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.

Example 2:

Input: S = "aaaaaaaaaa"
Output: 55
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int count_substrings(int n) {
        int res = 0;
        for (int k = 1; k <= n; ++k)
            res += (n-k+1);
        return res;
    }
    int countLetters(string S) {
        int res = 0;
        char ch = S[0];
        int slen = S.size();
        int prev = 0;
        for (int curr = 1; curr < slen; ++curr) {
            if (S[curr] != ch) {
                ch = S[curr];
                int len = curr - prev;
                res += count_substrings(len);
                prev = curr;
            }
        }
        int len = slen - prev;
        res += count_substrings(len);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aaaba";

    s = "aaaaaaaaaa";
    
    cout << "Res: " << sol.countLetters(s) << endl;
    
    return 0;
}
