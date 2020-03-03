/*
647. Palindromic Substrings
Medium

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.
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
    int cnt, sz;
    void expand (string& s, int i, int j) {
        for (; i >= 0 && j < sz; --i, ++j) {
            if (s[i] == s[j])
                ++cnt;
            else
                break;
        }
    }
    int countSubstrings(string s) {
        cnt = 0;
        sz = s.size();
        for (int i = 0; i < sz; ++i) {
            expand(s, i, i);
            expand(s, i-1, i);            
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 3
    s = "abc";
    cout << sol.countSubstrings(s) << endl;
    
    // Output: 6
    s = "aaa";
    cout << sol.countSubstrings(s) << endl;
    
    return 0;
}
