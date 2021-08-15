class Solution {
public:
    int findBlackPixel(vector<vector<char>>& p, int N) {
        if (p.empty()) return 0;
        int n = p.size(), m = p[0].size();
        vector<int> cc(m);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)  if (p[i][j] == 'B')
            ++cc[j];
        unordered_map<string,int> mp;
        for (int i = 0; i < n; ++i) mp[string(p[i].begin(), p[i].end())]++;
        int ans = 0;
        for (auto x:mp) if (x.second == N) {
            int cnt = 0, cur = 0;
            for (int i = 0; i < x.first.size(); ++i) if (x.first[i] == 'B') {
                ++cnt;
                if (cc[i] == N) ++cur;
            }
            if (cnt == N) ans += cur*N;
        }
        return ans;
    }
};
