/*
We can find each pair of s[i] != t[j]. Then try to extend both sides when s[i + t] == t[j + t]. If we have left steps
extended on the left side and right steps on the right side, we have (left + 1) * (right + 1) options for
this { i, j } case.

Example:
s = xbabc
t = ybbbc
For i = 2 and j = 2, we have s[i] = a and t[j] = b that doesn't match. Now look leftwards, we can extend left-side
by 1 time due to b, and extend right-side by 2 times due to bc. So for this specific center { i = 2, j = 2 },
we have 2 * 3 = 6 options.
*/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int M = s.size(), N = t.size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s[i] == t[j]) continue;
                int left = 1, right = 1;
                while (i - left >= 0 && j - left >= 0 && s[i - left] == t[j - left])
                    ++left;
                while (i + right < M && j + right < N && s[i + right] == t[j + right])
                    ++right;
                ans += left * right;
            }
        }
        return ans;
    }
};
