/*
737. Sentence Similarity II
Medium

We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be
represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs
similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:
They have the same length (i.e., the same number of words)
sentence1[i] and sentence2[i] are similar.
Notice that a word is always similar to itself, also notice that the similarity relation is transitive.
For example, if the words a and b are similar, and the words b and c are similar, then a and c are similar.


Example 1:
Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.

Example 2:
Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: true
Explanation: "leetcode" --> "platform" --> "anime" --> "manga" --> "onepiece".
Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.

Example 3:
Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: false
Explanation: "leetcode" is not similar to "onepiece".

Constraints:
1 <= sentence1.length, sentence2.length <= 1000
1 <= sentence1[i].length, sentence2[i].length <= 20
sentence1[i] and sentence2[i] consist of lower-case and upper-case English letters.
0 <= similarPairs.length <= 2000
similarPairs[i].length == 2
1 <= xi.length, yi.length <= 20
xi and yi consist of English letters.
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
    unordered_map <string, string> roots;

    string get_root(string& s) {
        roots.emplace(s, s);
        while (true) {
            string r = roots[s];
            if (r == s)
                break;
            s = r;
        }
        return s;
    }

    void join_root(string s, string & root) {
        while (true) {
            if (s == root)
                break;
            string t = roots[s];
            roots[s] = root;
            s = t;
        }
    }

    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        for(auto& p: pairs) {
            auto& a = p[0], b = p[1];
            auto ra = get_root(a), rb = get_root(b);
            if (ra < rb)
                join_root(b, ra);
            else if (rb < ra)
                join_root(a, rb);
        }

        if (words1.size() != words2.size())
            return false;
        for (int i = 0, n = words1.size(); i < n; ++i) {
            if (get_root(words1[i]) != get_root(words2[i]))
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
