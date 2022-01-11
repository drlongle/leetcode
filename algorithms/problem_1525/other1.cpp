/*
We first count each character (r[ch]), and number of distinct characters (d_r).
These are initial numbers for our right substring (thus, indicated as r).

As we move our split point from left to right, we "move" the current character to the left substring,
and update count and distinct characters in left and right substrings.
If the number of distict characters is equal, we increment the result.
*/

class Solution
{
public:
    int numSplits(string s)
    {
        int l[26] = {}, r[26] = {}, d_l = 0, d_r = 0, res = 0;
        for (auto ch : s)
            d_r += ++r[ch - 'a'] == 1;
        for (int i = 0; i < s.size(); ++i)
        {
            d_l += ++l[s[i] - 'a'] == 1;
            d_r -= --r[s[i] - 'a'] == 0;
            res += d_l == d_r;
        }
        return res;
    }
};