class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            if(l + 1 == nums[l])
                l++;
            else if(r + 1 == nums[r] || nums[r] <= 0 || nums[r] >= nums.size() || nums[nums[r] - 1] == nums[r])
                r--;
            else
                swap(nums[r], nums[nums[r] - 1]);
        }
        while(l < nums.size() && l + 1 == nums[l])
            l++;
        return l + 1;
    }
};
