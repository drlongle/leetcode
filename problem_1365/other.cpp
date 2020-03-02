class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; ++i) {
            int x = nums[i];
            auto it = lower_bound(sorted.begin(), sorted.end(), x);
            res[i] = it-sorted.begin();
        }
        return res;
    }
};
