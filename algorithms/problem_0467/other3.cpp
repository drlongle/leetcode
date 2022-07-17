class Solution {
  public:
    int findSubstringInWraproundString(string p) {
        int n = p.size(), cum = 0;
        vector<int> cnt(26, 0);

        for (int i = 0; i < n;) {
            if (cum == 0 || (p[i] - p[i - 1] == 1) ||
                (p[i - 1] == 'z' && p[i] == 'a')) {
                cum++;
                cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], cum);
                i++;
            } else
                cum = 0;
        }

        int ret = 0;
        for (int i = 0; i < 26; i++)
            ret += cnt[i];

        return ret;
    }
};
