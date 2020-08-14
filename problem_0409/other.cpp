class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> counters;
        for (const auto& c: s)
            ++counters[c];
        int len = 0;
        bool found_odd = false;
        for (const auto& p: counters)
        {
            found_odd |= (p.second & 0x01);
            len += p.second & (~0x01);
        }
        return len + found_odd;
    }
};
