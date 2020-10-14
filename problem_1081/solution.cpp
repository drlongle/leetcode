/*
1081. Smallest Subsequence of Distinct Characters
Medium

Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
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
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        for (char ch: s)
            ++cnt[ch-'a'];
        uint32_t seen = 0;
        string res;
        for (char ch: s) {
            --cnt[ch-'a'];
            if (seen & (1 << (ch - 'a')))
                continue;
            while (res.size() && res.back() > ch && cnt[res.back()-'a'] > 0) {
                seen &= ~(1 << (res.back() - 'a'));
                res.pop_back();
            }
            res.push_back(ch);
            seen |= 1 << (ch - 'a');
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;

    // Expected output: "abc"
    s = "bcabc";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    // Output: "acdb"
    s = "cbacdcbc";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    // Output: "bac"
    s = "bbbacacca";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "abccb";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "bccab";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "mitnlruhznjfyzmtmfnstsxwktxlboxutbic";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "yioccqiorhtoslwlvfgzycahonecugtatbyphpuunwvaalcpndabyldkdtzfjlgwqk";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "eywdgenmcnzhztolafcfnirfpuxmfcenlppegrcalgxjlajxmphwidqqtrqnmmbssotoywfrtylm";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    s = "wmxkuuoordmnpnebikzzujdpscpedcrsjphcaykjsmobturjjxxpoxvvrynmapegvtlasmyuddgxygkaztmbpkrnukbxityz";
    cout << "Result: " << sol.smallestSubsequence(s) << endl;

    return 0;
}
