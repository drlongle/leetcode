class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), cnt[2]{}, o = n >> 1;
        for (int i = 0; i < n; i++) cnt[i & 1] += s[i] & 1;
        int ans = cnt[0] + o - cnt[1];
        ans = min(ans, n - ans);
        for (int i = 0; n & 1 && i < n; i++) {
            swap(cnt[0], cnt[1]);
            cnt[0] += s[i] & 1;
            cnt[1] -= s[i] & 1;
            int t = cnt[0] + o - cnt[1];
            ans = min({ans, t, n - t});
        }
        return ans;
    }
};
