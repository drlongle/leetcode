// OJ: https://leetcode.com/problems/longest-nice-substring/
// Author: github.com/lzl124631x
// Time: O(N), the depth of the recursion is at most 26.
// Space: O(N)
// Two pointer technique

class Solution {
    string ans;
public:
    string longestNiceSubstring(string s) {
        int state[26] = {};
        for (char c : s) {
            if (isupper(c)) state[c - 'A'] |= 2;
            else state[c - 'a'] |= 1;
        }
        int i = 0, N = s.size();
        while (i < N) {
            int j = i;
            while (j < N && state[tolower(s[j]) - 'a'] == 3) ++j; // find the window only contain characters that in state 3, i.e. having both upper and lower case
            int len = j - i;
            if (len == N) { // this string itself is nice, update the answer
                ans = s;
                break;
            }
            if (len > ans.size()) longestNiceSubstring(s.substr(i, len)); // handle this window recursively. The recursion is at most 26 levels.
            while (j < N && state[tolower(s[j]) - 'a'] != 3) ++j;
            i = j;
        }
        return ans;
    }
};
