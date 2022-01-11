/*
1525. Number of Good Ways to Split a String
Medium

You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q
where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.

Example 1:
Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.

Example 2:
Input: s = "abcd"
Output: 1
Explanation: Split the string as follows ("ab", "cd").

Example 3:
Input: s = "aaaaa"
Output: 4
Explanation: All possible splits are good.

Example 4:
Input: s = "acbadbaada"
Output: 2

Constraints:
s contains only lowercase English letters.
1 <= s.length <= 10^5
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

class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> cnt1, cnt2;
        int res = 0, sz = s.size();
        for (int i = 0; i < sz; ++i)
            ++cnt1[s[i]];
        for (char ch: s) {
            auto it = cnt1.find(ch);
            if (--it->second == 0)
                cnt1.erase(it);
            ++cnt2[ch];
            res += cnt1.size() == cnt2.size();
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Output: 2
    s = "aacaba";
    cout << sol.numSplits(s) << endl;

    // Output: 1
    s = "abcd";
    cout << sol.numSplits(s) << endl;

    // Output: 4
    s = "aaaaa";
    cout << sol.numSplits(s) << endl;

    // Output: 2
    s = "acbadbaada";
    cout << sol.numSplits(s) << endl;

    return 0;
}
