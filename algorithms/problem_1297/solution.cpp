/*
1297. Maximum Number of Occurrences of a Substring
Medium

Given a string s, return the maximum number of ocurrences of any substring under the following rules:
* The number of unique characters in the substring must be less than or equal to maxLetters.
* The substring size must be between minSize and maxSize inclusive.

Example 1:
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

Example 2:
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.

Example 3:
Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3

Example 4:
Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0

Constraints:

1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s only contains lowercase English letters.
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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int sz = s.size();
        unordered_map<string, int> cnt;
        unordered_map<char, int> chars;
        
        int head = 0;
        for (; head < minSize-1; ++head)
            ++chars[s[head]];
        for (int tail = 0; tail + minSize - 1 < sz; ++tail) {
            ++chars[s[tail+minSize-1]];
            if (static_cast<int>(chars.size()) <= maxLetters)
                ++cnt[s.substr(tail, minSize)];                
            unordered_map<char, int> new_chars(chars);
            for (head = tail + minSize; head - tail + 1 <= maxSize && head < sz &&
                     static_cast<int>(new_chars.size()) <= maxLetters; ++head) {
                ++new_chars[s[head]];
                if (static_cast<int>(new_chars.size()) <= maxLetters)
                    ++cnt[s.substr(tail, head-tail+1)];
            }
            auto ch = s[tail];
            if (--chars[ch] == 0)
                chars.erase(ch);
        }
        
        if (cnt.empty())
            return 0;
        auto it = max_element(begin(cnt), end(cnt), [](auto& p1, auto& p2) {return p1.second < p2.second;});
        
        return it->second;
    }
};

int main() {
    Solution sol;
    string s;
    int maxLetters, minSize, maxSize;

    // Output: 2
    s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4;

    // Output: 2
    s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3;

    // Output: 3
    s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3;

    // Output: 0
    s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3;

    // Output: 1
    s = "abcde", maxLetters = 2, minSize = 2, maxSize = 4;

    // Output: 1
    s = "abcde", maxLetters = 3, minSize = 2, maxSize = 4;
    
    cout << "Result: " << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
    
    return 0;
}
