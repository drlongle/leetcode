class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> cnt;
        for (int n: nums)
            ++cnt[n];
        int lo = nums[0], sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            int n = nums[i];
            if (n <= lo) {
                lo = min(n, lo);
            } else {
                auto it2 = cnt.upper_bound(lo);
                if (it2->first < n)
                    return true;
            }
            auto it = cnt.find(n);
            if (--it->second == 0)
                cnt.erase(it);
        }
        
        return false;
    }
};
