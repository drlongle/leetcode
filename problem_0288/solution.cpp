/*
288. Unique Word Abbreviation
Medium

The abbreviation of a word is a concatenation of its first letter, the number of characters between the first
and last letter, and its last letter. If a word has only two characters, then it is an abbreviation of itself.

For example:

dog --> d1g because there is one letter between the first letter 'd' and the last letter 'g'.
internationalization --> i18n because there are 18 letters between the first letter 'i' and the last letter 'n'.
it --> it because any word with only two characters is an abbreviation of itself.
Implement the ValidWordAbbr class:

ValidWordAbbr(String[] dictionary) Initializes the object with a dictionary of words.
boolean isUnique(string word) Returns true if either of the following conditions are met (otherwise returns false):
There is no word in dictionary whose abbreviation is equal to word's abbreviation.
For any word in dictionary whose abbreviation is equal to word's abbreviation, that word and word are the same.


Example 1:

Input
["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique"]
[[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"]]
Output
[null, false, true, false, true]

Explanation
ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);
validWordAbbr.isUnique("dear"); // return false, dictionary word "deer" and word "dear" have the same abbreviation
                                // "d2r" but are not the same.
validWordAbbr.isUnique("cart"); // return true, no words in the dictionary have the abbreviation "c2t".
validWordAbbr.isUnique("cane"); // return false, dictionary word "cake" and word "cane" have the same abbreviation
                                // "c2e" but are not the same.
validWordAbbr.isUnique("make"); // return true, no words in the dictionary have the abbreviation "m2e".
validWordAbbr.isUnique("cake"); // return true, because "cake" is already in the dictionary and no other word
in the dictionary has "c2e" abbreviation.

Constraints:
1 <= dictionary.length <= 3 * 10^4
1 <= dictionary[i].length <= 20
dictionary[i] consists of lowercase English letters.
1 <= word.length <= 20
word consists of lowercase English letters.
At most 5000 calls will be made to isUnique.
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

class ValidWordAbbr {
public:
    unordered_map<string, string> table;
    string get_key(string& s) {
        int n = s.size() - 2;
        string key;
        if (n > 0) {
            key.push_back(s[0]);
            key += to_string(n);
            key.push_back(s.back());
        } else
            key = s;
        return key;
    }
    ValidWordAbbr(vector<string>& dictionary) {
        for (string& s: dictionary) {
            string key = get_key(s);
            auto [it, inserted] = table.emplace(key, s);
            if (!inserted && it->second != s)
                table[key] = "";
        }
    }

    bool isUnique(string word) {
        string key = get_key(word);
        auto it = table.find(key);
        return it == table.end() || it->second == word;
    }
};

int main() {
    return 0;
}
