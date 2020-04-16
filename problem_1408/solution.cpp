/*
1408. String Matching in an Array
Easy

Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

Example 1:
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Example 2:
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:
Input: words = ["blue","green","bu"]
Output: []

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int sz = words.size();
        set<string> res;
        for (int i = 0; i < sz; ++i) {
            auto si = words[i];
            for (int j = 0; j < sz; ++j) {
                auto sj = words[j];
                if (i != j && si.find(sj) != string::npos) {
                    res.emplace(sj);
                }
            }
        }
        return vector<string>(begin(res), end(res));
    }
};

int main() {
    Solution sol;
    vector<string> words, res;

    // Output: {"as","hero"}
    words = {"mass","as","hero","superhero"};
    res = sol.stringMatching(words);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"et","code"}
    words = {"leetcode","et","code"};
    res = sol.stringMatching(words);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    // Output: {}
    words = {"blue","green","bu"};
    res = sol.stringMatching(words);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    words = {"leetcoder","leetcode","od","hamlet","am"};
    res = sol.stringMatching(words);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
