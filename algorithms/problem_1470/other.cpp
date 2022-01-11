class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        auto _map = [&](int i) { return (i < n) ? (i<<1) : (((i-n)<<1) + 1); };
        auto _swap = [&](int i, int j) {
            swap(nums[i], nums[j]);
            nums[j] = -nums[j];
        };
        
        for (int i = 0; i < 2*n; ++i) {
            if (nums[i] < 0) continue;
            
            int j = i;
            do {
                j = _map(j);
                _swap(i, j);
            } while (j != i);
        }
        
        for (auto& v : nums) v = -v;
        
        return nums;
    }
};
