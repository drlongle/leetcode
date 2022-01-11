/*
784. Letter Case Permutation
Medium

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

Example 1:
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: S = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: S = "12345"
Output: ["12345"]

Example 4:
Input: S = "0"
Output: ["0"]

Constraints:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.
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
    int sz;
    vector<string> res;

    void backtrack(string& s, int level) {
        if (level == sz) {
            res.emplace_back(s);
            return;
        }

        int ch = s[level];
        if (isupper(ch)) {
            s[level] = tolower(ch);
            backtrack(s, level + 1);
        } else if (islower(ch)) {
            s[level] = toupper(ch);
            backtrack(s, level + 1);
        }
        s[level] = ch;
        backtrack(s, level + 1);
    }

    vector<string> letterCasePermutation(string s) {
        sz = s.size();
        backtrack(s, 0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> res;
    string s;

    s = "a1b2";
    res = sol.letterCasePermutation(s);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
