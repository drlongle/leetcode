/*
500. Keyboard Row
Easy

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Example:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
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
    int countRows(string& word) {
        unordered_set<int> rows;
        for (char ch: word) {
            ch = tolower(ch);
            rows.insert(lookup[ch - 'a']);
        }
        return rows.size();
    }

    vector<int> lookup;
    vector<string> findWords(vector<string>& words) {
        lookup.resize(26);
        vector<string> rows{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (size_t i = 0; i < rows.size(); ++i) {
            auto& row = rows[i];
            for (char ch: row)
                lookup[ch - 'a'] = i;
        }
        vector<string> res;
        for (auto& word: words) {
            if (countRows(word) == 1)
                res.emplace_back(word);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words, res;

    // Output: {"Alaska", "Dad"}
    words = {"Hello", "Alaska", "Dad", "Peace"};
    res = sol.findWords(words);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;
    
    return 0;
}
