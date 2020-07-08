class Solution {
public:
    long long hash(long long a, long long b, long long c) {
        return a * 100007 + b * 1007 + c;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<long long> cached;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_set<int> lookup;
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            for (int j = i+1; j < n; ++j) {
                int b = nums[j];
                int c = - (a + nums[j]);
                if (lookup.count(c)) {
                    auto r = hash(a, b, c);
                    if (!cached.count(r)) {
                        res.emplace_back(vector<int>{c, a, b});
                        cached.emplace(r);
                    }
                }

            }
            lookup.emplace(a);
        }
        return res;
    }
};
