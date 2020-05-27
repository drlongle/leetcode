/*
1456. Maximum Number of Vowels in a Substring of Given Length
Medium

Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Example 4:
Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.

Example 5:
Input: s = "tryhard", k = 4
Output: 1

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
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
    int maxVowels(string s, int k) {
        int sz = s.size(), begin = 0, end = 0, cnt = 0, res = 0;
        unordered_set<char> vowels{'a','e','i','o','u'};
        for (begin = 0; begin < k; ++begin)
            cnt += vowels.count(s[begin]);
        res = cnt;
        for (; begin < sz; ++begin, ++end) {
            cnt += vowels.count(s[begin]);
            cnt -= vowels.count(s[end]);
            res = max(res, cnt);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    int k;
    
    s = "abciiidef", k = 3;

    return 0;
}
