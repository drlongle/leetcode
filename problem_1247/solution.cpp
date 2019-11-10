/*
1247. Minimum Swaps to Make Strings Equal
Medium

You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only.
Your task is to make these two strings equal to each other. You can swap any two characters
that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

Example 1:
Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".

Example 2: 
Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.

Example 3:
Input: s1 = "xx", s2 = "xy"
Output: -1

Example 4:
Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
Output: 4
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
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int ans = 0;
        map<char, int> diff;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                char ch = s1[i];
                if (diff[ch] == 0) {
                    diff[ch] = 1;
                } else {
                    --diff[ch];
                    ++ans;
                }
            }
        }

        if (diff['x'] != diff['y'])
            return -1;
        return ans + diff['x'] / 2 + ((diff['x'] % 2 != 0) ? 2 : 0);
    }
};

int main() {
    Solution sol;
    string s1, s2;

    // Output: 1
    s1 = "xx", s2 = "yy";

    // Output: 2
    s1 = "xy", s2 = "yx";

    // Output: -1
    s1 = "xx", s2 = "xy";

    // Output: 4
    s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx";

    cout << "Result: " << sol.minimumSwap(s1, s2) << endl;
    
    return 0;
}
