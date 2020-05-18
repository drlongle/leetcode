/*
1451. Rearrange Words in a Sentence
Medium

Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
Return the new text following the format shown above.

Example 1:
Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.

Example 2:
Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.

Example 3:
Input: text = "To be or not to be"
Output: "To be or to be not"

Constraints:
text begins with a capital letter and then contains lowercase letters and single space between words.
1 <= text.length <= 10^5
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
    string arrangeWords(string text) {
        istringstream iss(text);
        string word;
        vector<pair<int, string>> words;
        int i = 0;
        while (getline(iss, word, ' ')) {
            if (i == 0)
                word[0] += ('a' - 'A');
            words.emplace_back(i++, word);
        }
        auto lambda = [] (auto& a, auto& b) {
                          size_t sa = a.second.size(), sb = b.second.size();
                          return sa < sb || (sa == sb && a.first < b.first);};
        sort(begin(words), end(words), lambda);
        ostringstream oss;
        bool first = true;
        for (auto& p: words) {
            if (!first)
                oss << ' ';
            else
                p.second[0] += ('A' - 'a');
            oss << p.second;
            first = false;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string text;

    text = "Leetcode is cool";
    cout << sol.arrangeWords(text) << endl;
    text = "Keep calm and code on";
    cout << sol.arrangeWords(text) << endl;    
    return 0;
}
