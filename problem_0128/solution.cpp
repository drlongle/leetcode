class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int res = 0;
        auto it = s.begin();
        while (it != s.end()) {
            int cnt = 1;
            auto nit = next(it);
            while (it != s.end() && nit != s.end() && ((*it + 1) == *(nit))) {
                ++cnt;
                ++it, ++nit;
            }
            res = max(res, cnt);
            ++it;
        }
        return res;
    }
};