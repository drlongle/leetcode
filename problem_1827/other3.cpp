class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                int t = (nums[i-1]-nums[i])+1;
                nums[i]+=t;
                count+=t;
            }
        }
        return count;
    }
};
