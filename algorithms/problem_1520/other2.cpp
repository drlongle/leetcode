/*
The greedy logic is quite simple:

- There could be no more that 26 valid substrings; each potential valid substring starts from the first occurrence of a given character.
- If we find a valid substring, and then another valid substring within the first substring - we can ignore the larger substring.
E.g. if we find "abccba", and then "bccb", and then "cc", we only care about "cc". This can be easily proven by a contradiction.

Algorithm:
1. First, collect left (l) and right(r) indices for every character.
2. Then, go through the string. If the current index i is the left index for the character s[i], it may be a valid substring.
    We then use a sliding window pattern to find the length of the substring.
    If we find a character that appears before i - we do not have a valid string starting at i.
    If substring is valid, we remember it, as well as it's right edge.
    This logic, repeated, will ensure that we find the valid substring with the smallest right edge.
3. If the valid substring starts after the previous right edge, there is no overlap. The previous substring should be included into the result.
*/
class Solution
{
public:
    int checkSubstr(string &s, int i, vector<int> &l, vector<int> &r)
    {
        int right = r[s[i] - 'a'];
        for (auto j = i; j <= right; ++j)
        {
            if (l[s[j] - 'a'] < i)
                return -1;
            right = max(right, r[s[j] - 'a']);
        }
        return right;
    }
    vector<string> maxNumOfSubstrings(string s)
    {
        vector<int> l(26, INT_MAX), r(26, INT_MIN);
        vector<string> res;
        for (auto i = 0; i < s.size(); ++i)
        {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        auto right = INT_MAX;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (i == l[s[i] - 'a'])
            {
                auto new_right = checkSubstr(s, i, l, r);
                if (new_right != -1)
                {
                    if (i > right || res.empty())
                        res.push_back("");
                    right = new_right;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }
        return res;
    }
};