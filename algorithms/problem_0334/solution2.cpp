class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> lo(n), hi(n);
        for (int i = 0, lowest = nums[0]; i < n; ++i) {
            lowest = lo[i] = min(lowest, nums[i]);
        }
        
        for (int i = n-1, highest = nums[n - 1]; i >= 0; --i) {
            highest = hi[i] = max(highest, nums[i]);
        }
        
        for (int i = 1; i < n-1; ++i) {
            if (lo[i-1] < nums[i] && nums[i] < hi[i+1])            
                return true;
        }
        
        return false;
    }
};
