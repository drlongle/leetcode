/*
1684. Count the Number of Consistent Strings
Easy

You are given a string allowed consisting of distinct characters and an array of strings words.
A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

Example 1:
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

Constraints:
1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> table(allowed.begin(), allowed.end());
        int cnt = 0;
        for (auto& w: words) {
            set<char> wtable(w.begin(), w.end());
            vector<char> v;
            set_difference(wtable.begin(), wtable.end(), table.begin(), table.end(), back_inserter(v));
            cnt += v.empty();
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    string allowed;
    vector<string> words;

    // Output: 2
    allowed = "ab", words = {"ad","bd","aaab","baa","badab"};
    cout << sol.countConsistentStrings(allowed, words) << endl;

    return 0;
}
