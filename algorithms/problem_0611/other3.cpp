class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        nums.erase(remove(begin(nums), end(nums), 0), end(nums));
        sort(begin(nums), end(nums));
        vector<int> v(2001);
        for (const auto val : nums) {
            ++v[val];
        }
        partial_sum(begin(v), end(v), begin(v));

        int ans = 0;
        for (int i = 0, n = size(nums); i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += v[nums[i] + nums[j] - 1] - j - 1;
            }
        }
        return ans;
    }

};
