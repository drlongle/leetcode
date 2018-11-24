/*
336. Palindrome Pairs

Difficulty:Hard
Total Accepted:42.9K
Total Submissions:155.5K

Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        vector<unordered_set<int>> forward(words.size()), backward(words.size());
        int nsize = static_cast<int>(words.size());
        for (int i = 0; i < nsize; ++i) {
            int wsize = words[i].size();
            for (int j = 0; j < wsize; ++j) {
                if (is_palindrome(words[i], 0, j)) {
                    forward[i].emplace(j);
                }
                if (is_palindrome(words[i], j, wsize-1)) {
                    backward[i].emplace(wsize-j);
                }
            }
        }

        for (int i = 0; i < nsize; ++i) {
            int ilen = words[i].size();
            string rs = words[i];
            reverse(begin(rs), end(rs));
            for (int j = 0; j < nsize; ++j) {
                if (i == j) continue;
                int jlen = words[j].size();
                if (ilen < jlen) {
                    int diff = jlen - ilen;
                    auto it = forward[j].find(diff-1);
                    if (it != forward[j].end() && words[j].compare(diff, ilen, rs) == 0) {
                        result.emplace_back(vector<int>{i, j});
                    }
                    it = backward[j].find(diff);
                    if (it != backward[j].end() && words[j].compare(0, ilen, rs) == 0) {
                        result.emplace_back(vector<int>{j, i});
                    }
                } else if (ilen == jlen && rs == words[j]) {
                    result.emplace_back(vector<int>{i, j});
                }
            }
        }

        return result;
    }

    bool is_palindrome(const string& s, int i, int j)
    {
        while (i < j) {
            if (s[i++] != s[j--])
	        return false;
        }

	return true;
    }

};

int main()
{
    Solution sol;

    vector<pair<vector<string>, vector<vector<int>>>> params {
        { {"abcd","dcba","lls","s","sssll"}, {{0,1},{1,0},{3,2},{2,4}} },
        { {"bat","tab","cat"}, {{0,1},{1,0}} }
    };
    vector<vector<int>> result;

    vector<string> input {"bat","tab","cat"};

    // [[0,1],[1,0],[3,2],[2,4]]
    input =  {"abcd","dcba","lls","s","sssll"};
    // input = {"a", ""};
    //input = {"a","abc","aba",""};
    //input = {"a","b","c","ab","ac","aa"};
    //input = {"a","aa","aaa"};

    result = sol.palindromePairs(input);
    for (auto& p: result)
	cout << '[' << p[0] << ',' << p[1] << "],";
    cout << endl;

    return 0;
}

