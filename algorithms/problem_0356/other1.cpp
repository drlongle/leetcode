class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, set<int>> mp;
        int l = INT_MAX;
        int r = INT_MIN;
        for (auto& p : points) {
            mp[p[1]].insert(p[0]);
            l = min(l, p[0]);
            r = max(r, p[0]);
        }
        int sum = (l + r);
        for (auto& level : mp) {
            auto& s = level.second;
            auto& h = level.first;
            for (auto& p : s) {
                if (mp[h].count(sum - p) == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
