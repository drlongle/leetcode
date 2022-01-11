/*
1422. Maximum Score After Splitting a String
Easy

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:
Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

Example 3:
Input: s = "1111"
Output: 3

Constraints:
2 <= s.length <= 500
The string s consists of characters '0' and '1' only.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int maxScore(string s) {
        int sz = s.size();
        int all_zeroes = count_if(begin(s), end(s), [](char ch) {return ch == '0';});
        int res = 0,  zeroes = 0;
        for (int i = 0; i < sz - 1; ++i) {
            if (s[i] == '0') {
                ++zeroes;
                --all_zeroes;
            }
            int curr = zeroes + (sz - i - 1 - all_zeroes);
            res = max(res, curr);
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 5 
    s = "011101";
    cout << sol.maxScore(s) << endl;

    // Output: 5
    s = "00111";
    cout << sol.maxScore(s) << endl;
    
    // Output: 3
    s = "1111";
    cout << sol.maxScore(s) << endl;
    
    return 0;
}
