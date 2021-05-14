/*
816. Ambiguous Coordinates
Medium

We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed all commas,
decimal points, and spaces, and ended up with the string s. Return a list of strings representing
all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0",
"0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.
Also, a decimal point within a number never occurs without at least one digit occuring before it,
so we never started with numbers like ".1".

The final answer list can be returned in any order. Also note that all coordinates in the final answer
have exactly one space between them (occurring after the comma.)

Example 1:
Input: s = "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]

Example 2:
Input: s = "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation:
0.0, 00, 0001 or 00.01 are not allowed.

Example 3:
Input: s = "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]

Example 4:
Input: s = "(100)"
Output: [(10, 0)]
Explanation:
1.0 is not allowed.

Note:
4 <= s.length <= 12.
s[0] = "(", s[s.length - 1] = ")", and the other elements in s are digits.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector <string> generate(string& s, int i, int j) {
        bool flag = s[i] != '0';
        vector <string > res;
        string sub = s.substr(i, j-i+1) ;
        int cnt = 0;
        for (int k = i; k <= j && s[k] == '0'; ++k){
            ++cnt;
        }
        if (!cnt || j == i)
            res.push_back(sub);
        int sz = sub.size();
        if (cnt == sz)
            return res;
        if (!flag) sz = min(2, sz);
        for (int l = 1; l < sz; ++l){
            if (sub.back() =='0')
                continue;
            sub.insert(l, 1, '.');
            if(sub[0] !='0' || sub[1] != '0')
                res.push_back (sub);

            sub.erase(l, 1);
        }

        return res;
    }

    vector<string> ambiguousCoordinates(string s) {
        vector <string> s1, s2, res;
        int n = s.size();
        for (int i = 1; i< n-2; ++i) {
            s1 = generate(s, 1, i);
            s2 = generate(s,i + 1, n - 2);
            for (auto x: s1) {
                for (auto y: s2) {
                    string t = '(' + x + ", " + y + ')';
                    res.push_back(t);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
