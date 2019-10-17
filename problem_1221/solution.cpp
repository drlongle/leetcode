/*
1221. Split a String in Balanced Strings
Easy

Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.

Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Example 2:
Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Example 3:
Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
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
    int balancedStringSplit(string s) {
        int res = 0, count = 0, sz = s.size();
        for (int i = 0; i < sz; ++i) {
            count +=  (s[i] == 'L') ? 1 : -1;
            if (count == 0)
                ++res;
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 4
    s = "RLRRLLRLRL";

    // Output: 3
    //s = "RLLLLRRRLR";

    // Output: 1
    //s = "LLLLRRRR";

    cout << "Result: " << sol.balancedStringSplit(s) << endl;
    
    return 0;
}
