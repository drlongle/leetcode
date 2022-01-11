/*
1371. Find the Longest Substring Containing Vowels in Even Counts
Medium

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Example 1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Example 2:
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Example 3:
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.

Constraints:
1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
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
#include <memory>
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
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowels{{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        unordered_map<char, int> cnt;
        unordered_map<int, int> htable{{0, -1}};
        int result = 0;
        int hash_index = 0;
        for (int char_index = 0, sz = s.size(); char_index < sz; ++char_index) {
            char ch = s[char_index];
            auto it = vowels.find(ch);
            if (it != vowels.end()) {
                int& c = cnt[ch];
                if (c == 0) {
                    hash_index += it->second;
                    c = 1;
                } else {
                    hash_index -= it->second;
                    c = 0;
                }
            }

            auto res = htable.emplace(hash_index, char_index);
            if (res.second == false) {
                result = max(result, char_index - res.first->second);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 13
    s = "eleetminicoworoep";
    cout << sol.findTheLongestSubstring(s) << endl;
    
    // Output: 5
    s = "leetcodeisgreat";
    cout << sol.findTheLongestSubstring(s) << endl;
    
    // Output: 6
    s = "bcbcbc";
    cout << sol.findTheLongestSubstring(s) << endl;
    
    return 0;
}
