/*
824. Goat Latin
Easy

A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.

Example 1:
Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Example 2:
Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

Notes:
S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
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
    string toGoatLatin(string s) {
        istringstream iss(s);
        ostringstream oss;

        string word;
        int index = 1;
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        while (iss.good()) {
            getline(iss, word, ' ');
            char ch = word[0];
            if (!vowels.count(tolower(ch))) {
                word.erase(0, 1);
                word.push_back(ch);
            }
            if (index != 1)
                oss << ' ';
            oss << word << "ma" << string(index, 'a');
            ++index;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string s;

    // Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
    s = "I speak Goat Latin";
    cout << sol.toGoatLatin(s) << endl;

    // Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
    s = "The quick brown fox jumped over the lazy dog";
    cout << sol.toGoatLatin(s) << endl;

    return 0;
}
