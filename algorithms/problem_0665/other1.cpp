class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<3) return true;
        int count=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]<nums[i-1] && nums[i]>nums[i+1]) return false;
            else if(nums[i]<nums[i-1] && nums[i]<=nums[i+1]){
                ++count;
            }
            else if(nums[i]>=nums[i-1] && nums[i]>nums[i+1]){
                if(nums[i+1]>=nums[i-1]) nums[i]=nums[i-1];
                else nums[i+1]=nums[i];
                ++count;
            }
            if(count==2) return false;
        }
        return true;
    }
};
