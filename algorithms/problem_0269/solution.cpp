/*
269. Alien Dictionary
Hard

There is a new alien language that uses the English alphabet. However, the order among the letters
is unknown to you. You are given a list of strings words from the alien language's dictionary,
where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically
increasing order by the new language's rules. If there is no solution, return "". If there
are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they
differ, the letter in s comes before the letter in t in the alien language. If the first
min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.

Example 1:
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"

Example 2:
Input: words = ["z","x"]
Output: "zx"

Example 3:
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
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

    vector<vector<bool>> graph = vector<vector<bool>>(26, vector<bool>(26, false));
    vector<bool> taken = vector<bool>(26, false);
    vector<bool> exist = vector<bool>(26, false);

    bool DFS(int id, vector<bool>& visited, string& res) {
        if (visited[id])
            return false;
        visited[id] = true;
        if (taken[id])
            return true;
        taken[id] = true;
        for (int i = 0; i < 26; ++i) {
            if (graph[i][id] && !DFS(i, visited, res)) {
                return false;
            }
        }
        visited[id] = false;
        res.push_back('a' + id);
        return true;
    }

    string alienOrder(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n-1; ++i) {
            auto& x = words[i];
            auto& y = words[i+1];
            size_t j;
            for (j = 0; j < min(x.size(), y.size()); ++j) {
                if (x[j] != y[j]) {
                    graph[y[j]-'a'][x[j]- 'a'] = true;
                    break;
                }
            }
            if (j == y.size() && j < x.size())
                return "";
        }
        for (auto& word: words) {
            for (char ch: word) {
                exist[ch - 'a'] = true;
            }
        }

        string res;
        for (int i = 0; i < 26; ++i) {
            vector<bool> visited(26, false);
            if (taken[i] || !exist[i])
                continue;
            if (!DFS(i, visited, res)) {
                return "";
            }
        }
        reverse(begin(res), end(res));

        return res;
    }
};

int main() {
    vector<string> words;

    // Output: "wertf"
    {
        Solution sol;
        words = {"wrt","wrf","er","ett","rftt"};
        cout << sol.alienOrder(words) << endl;
    }

    // Output: "zx"
    {
        Solution sol;
        words = {"z", "x"};
        cout << sol.alienOrder(words) << endl;
    }

    // Output: ""
    {
        Solution sol;
        words = {"z", "x", "z"};
        cout << sol.alienOrder(words) << endl;
    }

    // Output: "abc"
    {
        Solution sol;
        words = {"a","b","ca","cc"};
        cout << sol.alienOrder(words) << endl;
    }

    // Output: ""
    {
        Solution sol;
        words = {"abc","ab"};
        cout << sol.alienOrder(words) << endl;
    }

    return 0;
}
