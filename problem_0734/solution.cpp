/*
734. Sentence Similarity
Easy

We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode"
can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string
pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:
- They have the same length (i.e., the same number of words)
- sentence1[i] and sentence2[i] are similar.

Notice that a word is always similar to itself, also notice that the similarity relation is not transitive.
For example, if the words a and b are similar, and the words b and c are similar, a and c are not necessarily
similar.

Example 1:
Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"],
similarPairs = [["great","fine"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar
to the corresponding word in sentence2.

Example 2:
Input: sentence1 = ["great"], sentence2 = ["great"], similarPairs = []
Output: true
Explanation: A word is similar to itself.

Example 3:
Input: sentence1 = ["great"], sentence2 = ["doubleplus","good"], similarPairs = [["great","doubleplus"]]
Output: false
Explanation: As they don't have the same length, we return false.

Constraints:
1 <= sentence1.length, sentence2.length <= 1000
1 <= sentence1[i].length, sentence2[i].length <= 20
sentence1[i] and sentence2[i] consist of English letters.
0 <= similarPairs.length <= 1000
similarPairs[i].length == 2
1 <= xi.length, yi.length <= 20
xi and yi consist of lower-case and upper-case English letters.
All the pairs (xi, yi) are distinct.
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
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs)
    {
        unordered_map <string, unordered_set<string>> table;
        for (auto& sim: similarPairs) {
            table[sim[0]].insert(sim[1]);
            table[sim[1]].insert(sim[0]);
        }

        int n = sentence1.size();
        if (sentence2.size() != n)
            return false;
        for(int i = 0; i < n; ++i) {
            if (sentence1[i] != sentence2[i] && table[sentence1[i]].count(sentence2[i]) == 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
