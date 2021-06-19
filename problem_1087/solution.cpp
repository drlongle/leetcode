/*
1087. Brace Expansion
Medium

You are given a string s representing a list of words. Each letter in the word has one or more options.

If there is one option, the letter is represented as is.
If there is more than one option, then curly braces delimit the options. For example, "{a,b,c}" represents options ["a", "b", "c"].
For example, if s = "a{b,c}", the first character is always 'a', but the second character can be 'b' or 'c'.
The original list is ["ab", "ac"].

Return all words that can be formed in this manner, sorted in lexicographical order.

Example 1:
Input: s = "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]

Example 2:
Input: s = "abcd"
Output: ["abcd"]

Constraints:
1 <= s.length <= 50
s consists of curly brackets '{}', commas ',', and lowercase English letters.
s is guaranteed to be a valid input.
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    string curr;
    vector<string> res;
    int sz;

    void backtrack(string& s, int index) {
        if (index == sz) {
            res.push_back(curr);
            return;
        }
        char c = s[index];
        if (isalpha(c)) {
            curr.push_back(c);
            backtrack(s, index + 1);
            curr.pop_back();
        } else {
            int j;
            vector<char> alts;
            for (j = index + 1; s[j] != '}'; ++j) {
                if (isalpha(s[j]))
                    alts.push_back(s[j]);
            }
            sort(begin(alts), end(alts));
            for (char c: alts) {
                curr.push_back(c);
                backtrack(s, j + 1);
                curr.pop_back();
            }
        }
    }

    vector<string> expand(string s) {
        sz = s.size();
        backtrack(s, 0);
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
