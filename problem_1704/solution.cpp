/*
1704. Determine if String Halves Are Alike
Easy

You are given a string s of even length. Split this string into two halves of equal lengths,
and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels
('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.

Example 3:
Input: s = "MerryChristmas"
Output: false

Example 4:
Input: s = "AbCdEfGh"
Output: true

Constraints:
2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        auto lambda = [&] (char ch) {return vowels.count(tolower(ch));};
        int total_vowels = count_if(begin(s), end(s), lambda);
        auto ss = s.substr(0, s.size()/2);
        return total_vowels == 2 * count_if(begin(ss), end(ss), lambda);
    }
};

int main() {
    Solution sol;
    string s;

    // true
    s = "book";
    cout << boolalpha << sol.halvesAreAlike(s) << endl;

    // false
    s = "textbook";
    cout << boolalpha << sol.halvesAreAlike(s) << endl;

    // false
    s = "MerryChristmas";
    cout << boolalpha << sol.halvesAreAlike(s) << endl;

    // true
    s = "AbCdEfGh";
    cout << boolalpha << sol.halvesAreAlike(s) << endl;

    // false
    s = "tkPAdxpMfJiltOerItiv";
    cout << boolalpha << sol.halvesAreAlike(s) << endl;

    return 0;
}
