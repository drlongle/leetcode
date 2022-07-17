class Solution {
  public:
    int findSubstringInWraproundString(string p) {
        vector<int> ct(26, 0);
        int len = 1;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i] + 25 == p[i - 1]))
                len++;
            else
                len = 1;
            ct[p[i] - 'a'] = max(len, ct[p[i] - 'a']);
        }
        int ans = 0;
        for (auto &e : ct)
            ans += e;
        return ans;
    }
};
