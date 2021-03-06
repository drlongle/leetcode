class Solution {
public:
    int numberOfSubstrings(string s, int res = 0) {
        for (int i = 0, j = 0, cnt[3] = {}; i < s.size(); res += j) {
            ++cnt[s[i++] - 'a'];
            while (cnt[0] && cnt[1] && cnt[2]) 
                --cnt[s[j++] - 'a'];
        }
        return res;
    }
};
