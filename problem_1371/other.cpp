/*
We can track whether we have an even or odd number of each vowel using a bit mask. Since we only have 5 vowels in the English alphabet, we will have 32 possible combinations.

As we go through our string, we update mask, and track the smallest index for each mask combination. If we encounter the same mask later in the string, that means the string between smallest (exclusive) and current (inclusive) index meets the problem criteria.

In other words, we need to find the maximum distance between the first and last index for each mask combination.

Note that for zero mask (all vowels' count is even), the first index is '-1' - so that we include the string from very beginning.
*/

class Solution {
public:
    static constexpr char c_m[26] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};    
    int findTheLongestSubstring(string s) {
        int mask = 0, res = 0;
        vector<int> m(32, -1);
        for (int i = 0; i < s.size(); ++i) {
            mask ^= c_m[s[i] - 'a'];
            if (mask != 0 && m[mask] == -1)
                m[mask] = i;
            res = max(res, i - m[mask]);
        }
        return res;
    }
};
