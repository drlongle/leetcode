/*
1813. Sentence Similarity III
Medium

You are given two strings sentence1 and sentence2, each representing a sentence
composed of words. A sentence is a list of words that are separated by a single
space with no leading or trailing spaces. Each word consists of only uppercase
and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an
arbitrary sentence (possibly empty) inside one of these sentences such that the
two sentences become equal. Note that the inserted sentence must be separated
from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by
inserting "my name is" between "Hello" and "Jane" in s1. s1 = "Frog cool" and s2
= "Frogs are cool" are not similar, since although there is a sentence "s are"
inserted into s1, it is not separated from "Frog" by a space. Given two
sentences sentence1 and sentence2, return true if sentence1 and sentence2 are
similar. Otherwise, return false.

Example 1:
Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
Output: true
Explanation:
sentence2 can be turned to sentence1 by inserting "name is" between "My" and
"Haley".

Example 2:
Input: sentence1 = "of", sentence2 = "A lot of words"
Output: false
Explanation:
No single sentence can be inserted inside one of the sentences to make it equal
to the other.

Example 3:
Input: sentence1 = "Eating right now", sentence2 = "Eating"
Output: true
Explanation:
sentence2 can be turned to sentence1 by inserting "right now" at the end of the
sentence.

Constraints:
1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and
spaces. The words in sentence1 and sentence2 are separated by a single space.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<string> split(string &s) {
        vector<string> res;
        size_t cur = 0;
        while (true) {
            size_t next = s.find(' ', cur);
            if (next == string::npos) {
                res.emplace_back(s.substr(cur));
                break;
            } else {
                res.emplace_back(s.substr(cur, next - cur));
                cur = next + 1;
            }
        }

        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto s1 = split(sentence1);
        auto s2 = split(sentence2);
        if (s1.size() < s2.size())
            return areSentencesSimilar(sentence2, sentence1);
        if (s1.size() == s2.size())
            return sentence1 == sentence2;

        int diff_size = s1.size() - s2.size();
        if (vector<string>(s1.begin(), s1.begin() + s2.size()) == s2)
            return true;
        if (vector<string>(s1.begin() + diff_size, s1.end()) == s2)
            return true;
        for (size_t sz = 0; sz < s2.size(); ++sz) {
            if (vector<string>(s2.begin(), s2.begin() + sz) ==
                    vector<string>(s1.begin(), s1.begin() + sz) &&
                vector<string>(s2.begin() + sz, s2.end()) ==
                    vector<string>(s1.begin() + sz + diff_size, s1.end()))
                return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    string sentence1, sentence2;

    sentence1 = "My name is Haley", sentence2 = "My Haley";
    cout << boolalpha << sol.areSentencesSimilar(sentence1, sentence2) << endl;

    sentence1 = "of", sentence2 = "A lot of words";
    cout << boolalpha << sol.areSentencesSimilar(sentence1, sentence2) << endl;

    sentence1 = "Eating right now", sentence2 = "Eating";
    cout << boolalpha << sol.areSentencesSimilar(sentence1, sentence2) << endl;

    return 0;
}
