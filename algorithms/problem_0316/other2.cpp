class Solution {
public:
    static string removeDuplicateLetters(const string& s) {
        uint16_t last[26];
        for (int i = 0; i < s.length(); ++i) last[s[i] - 'a'] = i;
        uint32_t seen = 0;

        string ans;
        for (int i = 0; i < s.length(); ++i)  {
            if (seen & (1 << s[i] - 'a')) continue;
            while (!ans.empty() && s[i] < ans.back() && i < last[ans.back() - 'a']) {
                seen &= ~(1 << ans.back() - 'a');
                ans.pop_back();
            }
            seen |= 1 << s[i] - 'a';
            ans.push_back(s[i]);
        }

        return ans;
    }
};