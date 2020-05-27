class Solution {
public:
    int maxVowels(string s, int k) {
        map<int, int> vow;
        vow['a'] = 1;vow['e'] = 1;vow['i'] = 1;vow['o'] = 1;vow['u'] = 1;
        int ans = 0, cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            cnt += vow[s[i]];
            if(i >= k)
                cnt -= vow[s[i-k]];
            ans = max(ans, cnt);
        }
        return ans;
    }
};
