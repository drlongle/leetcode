/*
937. Reorder Data in Log Files
Medium

You are given an array of logs. Each log is a space-delimited string of words,
where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English
letters. Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their
contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

Example 1:
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3
art zero"] Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1
5 1","dig2 3 6"] Explanation: The letter-log contents are all different, so
their ordering is "art can", "art zero", "own kit dig". The digit-logs have a
relative order of "dig1 8 1 5 1", "dig2 3 6".

Example 2:
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act
zoo"] Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4
7"]

Constraints:
1 <= logs.length <= 100
3 <= logs[i].length <= 100
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the
identifier.
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> digit_logs;
        vector<pair<string, string>> letter_logs;
        for (int i = 0, sz = logs.size(); i < sz; ++i) {
            auto &log = logs[i];
            auto p1 = log.find(' ');

            bool digit_flag = true;
            for (auto j = p1 + 1; digit_flag && j < log.size(); ++j) {
                if (log[j] != ' ')
                    digit_flag = isdigit(log[j]);
            }
            if (digit_flag) {
                digit_logs.push_back(log);
            } else {
                letter_logs.emplace_back(log.substr(0, p1), log.substr(p1));
            }
        }

        auto lambda = [](auto &a, auto &b) {
            return a.second < b.second ||
                   (a.second == b.second && a.first < b.first);
        };
        sort(begin(letter_logs), end(letter_logs), lambda);

        vector<string> res;
        for (auto &log : letter_logs)
            res.emplace_back(log.first + log.second);
        for (auto &log : digit_logs)
            res.emplace_back(log);
        return res;
    }
};

int main() {
    return 0;
}
