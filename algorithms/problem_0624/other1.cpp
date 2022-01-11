
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0, lo = 10001, hi = -10001;
        for (auto &v : arrays) {
            int lo2 = v.front(), hi2 = v.back();
            ans = max({ans, hi - lo2, hi2 - lo});
            hi = max(hi, hi2), lo = min(lo, lo2);
        }
        return ans;
    }
};
