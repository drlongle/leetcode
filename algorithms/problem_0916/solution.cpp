/*
916. Word Subsets
Medium

We are given two arrays A and B of words. Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.
For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a.

Return a list of all universal words in A. You can return the words in any order.

Example 1:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]

Example 3:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]

Example 4:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]

Example 5:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]

Note:
1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] and B[i] consist only of lowercase letters.
All words in A[i] are unique: there isn't i != j with A[i] == A[j].
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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> required(26, 0), cur(26, 0);
        for (auto& b: B) {
            std::fill(cur.begin(), cur.end(), 0);
            for (char c: b)
                ++cur[c - 'a'];
            for (int i = 0; i < 26; ++i)
                required[i] = max(required[i], cur[i]);
        }

        vector<string> res;
        for (string& a: A) {
            std::fill(cur.begin(), cur.end(), 0);
            bool cover = true;
            for (char c: a)
                ++cur[c - 'a'];
            for (int i = 0; i < 26 && cover; ++i)
                cover &= cur[i] >= required[i];
            if (cover)
                res.push_back(move(a));
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> A, B, res;

    // Output: {"facebook","google","leetcode"}
    A = {"amazon","apple","facebook","google","leetcode"}, B = {"e","o"};
    res = sol.wordSubsets(A, B);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"apple","google","leetcode"}
    A = {"amazon","apple","facebook","google","leetcode"}, B = {"l","e"};
    res = sol.wordSubsets(A, B);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"facebook","google"}
    A = {"amazon","apple","facebook","google","leetcode"}, B = {"e","oo"};
    res = sol.wordSubsets(A, B);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"google","leetcode"}
    A = {"amazon","apple","facebook","google","leetcode"}, B = {"lo","eo"};
    res = sol.wordSubsets(A, B);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"facebook","leetcode"}
    A = {"amazon","apple","facebook","google","leetcode"}, B = {"ec","oc","ceo"};
    res = sol.wordSubsets(A, B);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
