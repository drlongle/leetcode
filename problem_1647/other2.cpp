class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> cnt(26);
        for(char i : s)
            cnt[i-'a']++;
        vector<int> len(n+1);
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0) {
                len[cnt[i]]++;
            }
        }
        int ans = 0;
        for(int i = n; i > 0; i--) {
            if(len[i] > 1) { // len[i]: number of characters that appears i times
                ans += len[i] - 1;
                len[i-1] += len[i] - 1;
            }
        }

        return ans;
    }
};
