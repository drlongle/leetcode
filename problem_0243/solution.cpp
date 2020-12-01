/*
243. Shortest Word Distance
Easy

Given a list of words and two words word1 and word2, return the shortest distance between
these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
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
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, n = words.size(), res = n - 1;
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1)
                p1 = i;
            if (words[i] == word2)
                p2 = i;
            if (p1 >= 0 && p2 >= 0)
                res = min(res, abs(p1 - p2));
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    string word1, word2;

    words = {"a","c","b","a"}, word1 = "a", word2 = "b";
    cout << sol.shortestDistance(words, word1, word2) << endl;

    return 0;
}
