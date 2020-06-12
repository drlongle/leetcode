/*
1048. Longest String Chain
Medium

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

Example 1:
Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".

Note:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool preceed(string& s1, string& s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        if (sz1 + 1 != sz2)
            return false;
        int skip = 0;
        for (int i = 0; i < sz1; ) {
            if (s1[i] != s2[i + skip]) {
                if (skip == 0)
                    skip = 1;
                else
                    return false;
            } else
                ++i;
        }
        return true;
    }

    unordered_map<int, unordered_set<int>> graph;
    vector<int> dp;

    int dfs(int id) {
        if (dp[id] > 0)
            return dp[id];
        int dist = 0;
        for (int nid: graph[id])
            dist = max(dist, dfs(nid));
        return dp[id] = 1 + dist;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        dp.resize(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (preceed(words[i], words[j]))
                    graph[i].emplace(j);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i));
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;

    {
        // Output: 4
        words = {"a","b","ba","bca","bda","bdca"};
        cout << sol.longestStrChain(words) << endl;
    }

    {
        // Output: 7
        words = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
        cout << sol.longestStrChain(words) << endl;
    }

    {
        // Output: 8
        words = {"qyssedya","pabouk","mjwdrbqwp","vylodpmwp","nfyqeowa","pu","paboukc","qssedya","lopmw","nfyqowa","vlodpmw","mwdrqwp","opmw","qsda","neo","qyssedhyac","pmw","lodpmw","mjwdrqwp","eo","nfqwa","pabuk","nfyqwa","qssdya","qsdya","qyssedhya","pabu","nqwa","pabqoukc","pbu","mw","vlodpmwp","x","xr"};
        cout << sol.longestStrChain(words) << endl;
    }
        
    return 0;
}
