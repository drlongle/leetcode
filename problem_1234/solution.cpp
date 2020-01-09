/*
1234. Replace the Substring for Balanced String
Medium

You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.
A string is said to be balanced if each of its characters appears n/4 times
where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string
of the same length to make the original string s balanced.
Return 0 if the string is already balanced. 

Example 1:
Input: s = "QWER"
Output: 0
Explanation: s is already balanced.

Example 2:
Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.

Example 3:
Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". 

Example 4:
Input: s = "QQQQ"
Output: 3
Explanation: We can replace the last 3 'Q' to make s = "QWER".

Constraints:
1 <= s.length <= 10^5
s.length is a multiple of 4
s contains only 'Q', 'W', 'E' and 'R'.
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
    bool is_contained(map<char, int>& c1, map<char, int>& c2) {
        for (auto& p: c1) {
            if (c2[p.first] < p.second)
                return false;
        }
        return true;
    }
    
    int balancedString(string s) {
        int sz = s.size();
        int share = sz / 4;
        map<char, int> counts, running;
        for (char ch: {'Q', 'W', 'E', 'R'}) {
            int surplus = count_if(begin(s), end(s), [ch] (char c) {return ch == c;}) - share;
            if (surplus > 0)
                counts[ch] = surplus;
        }
        if (counts.empty())
            return 0;
        int res = sz;
        for (int head = 0, tail = 0; head < sz; ++head) {
            char ch = s[head];
            ++running[ch];
            while (is_contained(counts, running) && tail <= head) {
                res = min(res, head - tail + 1);
                ch = s[tail];
                --running[ch];
                ++tail;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 0
    s = "QWER";

    // Output: 1
    //s = "QQWE";

    // Output: 2
    //s = "QQQW";

    // Output: 3
    //s = "QQQQ";

    cout << "Result: " << sol.balancedString(s) << endl;
    
    return 0;
}
