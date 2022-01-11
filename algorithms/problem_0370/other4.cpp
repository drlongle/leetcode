class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, int> m;
        for(auto u : updates) {
            m[u[0]] += u[2];
            m[u[1] + 1] -= u[2];
        }
        vector<int> ans(length);
        int cnt = 0;
        for(auto it = m.begin(); it != m.end(); ++it) {
            cnt += it->second;
            if(cnt != 0) {
                auto nt = it;
                ++nt;
                if(nt != m.end())
                    for(int i = it->first; i < nt->first; ++i)
                        ans[i] += cnt;
            }
        }
        return ans;
    }
};
