class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0;
        for(int i = 0, left = 0, prod = 1; i < nums.size(); i++){
            prod *= nums[i];
            while(left <= i && prod >= k) prod/=nums[left++];
            ans += i - left + 1;
        }
        return ans;
    }
};
