/*
527. Word Abbreviation
Hard

Given an array of distinct strings words, return the minimal possible abbreviations for every word.

The following are the rules for a string abbreviation:

Begin with the first character, and then the number of characters abbreviated, followed by the last character.
If there is any conflict and more than one word shares the same abbreviation, a longer prefix is used instead
of only the first character until making the map from word to abbreviation become unique. In other words,
a final abbreviation cannot map to more than one original word.
If the abbreviation does not make the word shorter, then keep it as the original.

Example 1:
Input: words = ["like","god","internal","me","internet","interval","intension","face","intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

Example 2:
Input: words = ["aa","aaa"]
Output: ["aa","aaa"]

Constraints:
1 <= words.length <= 400
2 <= words[i].length <= 400
words[i] consists of lowercase English letters.
All the strings of words are unique.
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int sz = words.size();
        vector<string> res(sz);
        for (int cnt = 0, pre = 1; cnt < sz; ++pre) {
            unordered_map<string, int> table;
            for (int i = 0; i < sz; ++i) {
                if (res[i].size())
                    continue;
                auto& word = words[i];
                if (pre + 2 >= word.size()) {
                    res[i] = word;
                    ++cnt;
                } else {
                    string s = word.substr(0, pre) + to_string(word.size() - pre - 1) + word.back();
                    ++table[s];
                }
            }

            for (int i = 0; i < sz; ++i) {
                if (res[i].size())
                    continue;
                auto& word = words[i];
                string s = word.substr(0, pre) + to_string(word.size () - pre - 1) + word.back();
                if (table[s] == 1) {
                    res[i] = s;
                    ++cnt;
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
