class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i=1; i<n;++i){
            if(nums[i]<nums[i-1]){
                swap(nums[i],nums[i-1]);
                ++i;
            }
        }
        return is_sorted(begin(nums),end(nums));
    }
};