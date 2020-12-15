/*
425. Word Squares

    Difficulty: Hard

Given a set of words (without duplicates), find all word squares you can build
from them. Note:

    There are at least 1 and at most 1000 words.
    All words will have the exact same length.
    Word length is at least 1 and at most 5.
    Each word contains only lowercase English alphabet a-z.

Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter
(just the order of words in each word square matters).

Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter
(just the order of words in each word square matters).

 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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

    struct Node {
        vector<int> indices;
        map<char, Node> children;
    };

    Node root;

    void insert(string& word, int index) {
        Node* n = &root;
        n->indices.push_back(index);
        for (char ch: word) {
            n = &n->children[ch];
            n->indices.push_back(index);
        }
    }

    vector<int>& get(string& word) {
        Node* n = &root;
        for (char ch: word) {
            n = &n->children[ch];
        }
        return n->indices;
    }

    vector<vector<string>> res;
    vector<string> matrix;
    size_t wlen;

    void dfs(vector<string>& words, string& path) {
        auto& indices = get(path);
        size_t msz = matrix.size();
        for (int j: indices) {
            matrix.emplace_back(words[j]);
            string new_path;
            for (size_t i = 0; i < msz + 1; ++i) {
                if (msz + 1 < wlen)
                    new_path.push_back(matrix[i][msz+1]);
            }
            if (matrix.size() == wlen)
                res.emplace_back(matrix);
            else
                dfs(words, new_path);
            matrix.pop_back();
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        int wsz = words.size();
        for (int i = 0; i < wsz; ++i)
            insert(words[i], i);

        wlen = words[0].size();
        string path;

        dfs(words, path);

        return res;
    }
};

int main(int argc, const char* argv[])
{
    vector<string> words;
    vector<vector<string>> result;

    {
        Solution sol;
        words = {"area","lead","wall","lady","ball"};
        result = sol.wordSquares(words);
        for (auto& res: result)
        {
            copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));
            cout << endl;
        }
    }

    {
        Solution sol;
        words = {"abat","baba","atan","atal"};
        result = sol.wordSquares(words);
        for (auto& res: result)
        {
            copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));
            cout << endl;
        }
    }

    return 0;
}

