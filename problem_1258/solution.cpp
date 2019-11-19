/*
1258. Synonymous Sentences
Medium

Given a list of pairs of equivalent words synonyms and a sentence text, Return all possible
synonymous sentences sorted lexicographically. 

Example 1:
Input:
synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
text = "I am happy today but was sad yesterday"
Output:
["I am cheerful today but was sad yesterday",
​​​​​​​"I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday",
"I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday",
"I am joy today but was sorrow yesterday"]

Constraints:

0 <= synonyms.length <= 10
synonyms[i].length == 2
synonyms[0] != synonyms[1]
All words consist of at most 10 English letters only.
text is a single space separated sentence of at most 10 words.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:

    string get_root(string s) {
        while (s != graph[s])
            s = graph[s];
        return s;
    }

    void join_root(string s, string root) {
        do {
            string temp = graph[s];
            graph[s] = root;
            s = temp;
        } while (s != root);
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (auto& pair: synonyms) {
            string s1 = pair[0];
            string s2 = pair[1];
            if (!graph.count(s1))
                graph[s1] = s1;
            if (!graph.count(s2))
                graph[s2] = s2;
            auto r1 = get_root(s1);
            auto r2 = get_root(s2);
            if (r1 < r2)
                join_root(s2, r1);
            else
                join_root(s1, r2);
        }

        for (auto& p: graph) {
            dict[p.second].emplace(p.first);
        }
        
        vector<string> res{""};
        istringstream iss(text);
        string s;
        bool first = true;
        while (getline(iss, s, ' ')) {

            vector<string> new_res;
            for (auto r: res) {
                if (!first)
                    r += " ";
                if (graph.count(s)) {
                    auto root = get_root(s);
                    for (auto& word: dict[root])
                        new_res.emplace_back(r + word);
                } else {
                    r += s;
                    new_res.emplace_back(r);
                }
            }
            first = false;
            res = new_res;
        }

        return res;
    }

    map<string, string> graph;
    map<string, set<string>> dict;
};

int main() {
    Solution sol;
    vector<vector<string>> synonyms;
    string text;
    
    /*
    Output:
    ["I am cheerful today but was sad yesterday",
     "I am cheerful today but was sorrow yesterday",
     "I am happy today but was sad yesterday",
     "I am happy today but was sorrow yesterday",
     "I am joy today but was sad yesterday",
     "I am joy today but was sorrow yesterday"]
    */

    synonyms = {{"happy","joy"},{"sad","sorrow"},{"joy","cheerful"}};
    text = "I am happy today but was sad yesterday";

    auto res = sol.generateSentences(synonyms, text);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "\n"));
        
    return 0;
}
