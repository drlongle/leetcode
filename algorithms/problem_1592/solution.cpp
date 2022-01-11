/*
1592. Rearrange Spaces Between Words
Easy

You are given a string text of words that are placed among some number of spaces. Each word consists of one or more
lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.

Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number
is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the
returned string should be the same length as text.

Return the string after rearranging the spaces.

Example 1:
Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words:
9 / (4-1) = 3 spaces.

Example 2:
Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra
space at the end of the string.

Example 3:
Input: text = "hello   world"
Output: "hello   world"

Example 4:
Input: text = "  walks  udp package   into  bar a"
Output: "walks  udp  package  into  bar  a "

Example 5:
Input: text = "a"
Output: "a"

Constraints:
1 <= text.length <= 100
text consists of lowercase English letters and ' '.
text contains at least one word.
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

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;

        int sz = text.size(), spaces = 0, i = 0;
        while (i < sz) {
            if (text[i] == ' ') {
                ++spaces;
                ++i;
                continue;
            }

            int start = i;
            while (i < sz && text[i] != ' ')
                ++i;
            words.emplace_back(text.substr(start, i - start));
        }

        int wsz = words.size();
        int spacing = (wsz > 1) ? spaces / (wsz - 1) : spaces;
        spaces -= (wsz > 1) ? spacing * (wsz - 1) : 0;
        string space(spacing, ' ');
        string last_space(spaces, ' ');

        ostringstream oss;
        for (int i = 0; i < wsz; ++i) {
            oss << words[i];
            if (i < wsz - 1)
                oss << space;
        }
        oss << last_space;

        return oss.str();
    }
};

int main() {
    Solution sol;
    string text;

    // Output: "this   is   a   sentence"
    text = "  this   is  a sentence ";
    cout << sol.reorderSpaces(text) << endl;

    // Output: "practice   makes   perfect "
    text = " practice   makes   perfect";
    cout << sol.reorderSpaces(text) << endl;

    // Output: "hello   world"
    text = "hello   world";
    cout << sol.reorderSpaces(text) << endl;

    // Output: "walks  udp  package  into  bar  a "
    text = "  walks  udp package   into  bar a";
    cout << sol.reorderSpaces(text) << endl;

    // Output: "a"
    text = "a";
    cout << sol.reorderSpaces(text) << endl;

    return 0;
}
