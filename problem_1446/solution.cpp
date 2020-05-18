/*
1446. Consecutive Characters
Easy

Given a string s, the power of the string is the maximum length of a non-empty substring
that contains only one unique character. Return the power of the string.

Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Example 3:
Input: s = "triplepillooooow"
Output: 5

Example 4:
Input: s = "hooraaaaaaaaaaay"
Output: 11

Example 5:
Input: s = "tourist"
Output: 1

Constraints:
1 <= s.length <= 500
s contains only lowercase English letters.
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
    int maxPower(string s) {
        int res = 0, cnt = 0;
        char cur = ' ';
        for (char c: s) {
            if (cur == c)
                res = max(res, ++cnt);
            else {
                cur = c;
                cnt = 1;
                res = max(res, cnt);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 2
    s = "leetcode";
    cout << sol.maxPower(s) << endl;
    
    // Output: 5
    s = "abbcccddddeeeeedcba";
    cout << sol.maxPower(s) << endl;
    
    // Output: 5
    s = "triplepillooooow";
    cout << sol.maxPower(s) << endl;
    
    // Output: 11
    s = "hooraaaaaaaaaaay";
    cout << sol.maxPower(s) << endl;
    
    // Output: 1
    s = "tourist";
    cout << sol.maxPower(s) << endl;

    return 0;
}
