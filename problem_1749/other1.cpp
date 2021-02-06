class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int cur_max = nums[0],cur_min = nums[0];
        int max_sum = nums[0],min_sum = nums[0];

        for(int i=1;i<nums.size();i++){
            int n = nums[i];
            cur_max = max(cur_max+n,n);
            max_sum = max(cur_max,max_sum);
            cur_min = min(cur_min+n,n);
            min_sum = min(min_sum, cur_min);
        }
        return max(abs(max_sum),abs(min_sum));
    }
};
