class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int n = nums.size();
        vector<long long> v(n + 1);
        for (const auto& r : requests) {
            ++v[r[0]];
            --v[r[1] + 1];
        }
        for (int i = 1; i < n; ++i) {
            v[i] += v[i - 1];
        }
        v.pop_back();
        sort(v.begin(), v.end());
        sort(nums.begin(), nums.end());
        long long r = 0;
        for (int i = 0 ; i < n; ++i) {
            r += v[i] * nums[i];
        }
        return r % 1000000007;

    }
};
