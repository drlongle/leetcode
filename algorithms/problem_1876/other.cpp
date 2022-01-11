class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt[123] = {}, repeat = 0, res = 0;
        for(int i = 0; i < s.size(); ++i) {
            repeat += cnt[s[i]]++ == 1;
            repeat -= i >= 3 && cnt[s[i - 3]]-- == 2;
            res += i >= 2 && repeat == 0;
        }
        return res;
    }
};