/*
1119. Remove Vowels from a String
User Accepted: 858
User Tried: 868
Total Accepted: 872
Total Submissions: 941
Difficulty: Easy

Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

Example 1:
Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Example 2:
Input: "aeiou"
Output: ""

Note:
S consists of lowercase English letters only.
1 <= S.length <= 1000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

    string removeVowels(string st) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        ostringstream oss;
        for (const auto& ch: st) {
            if (vowels.count(ch) == 0)
                oss << ch;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string st;

    st = "ltcdscmmntyfrcdrs";
    st = "aeiou";

    cout << "Result: " << sol.removeVowels(st) << endl;

    return 0;
}

