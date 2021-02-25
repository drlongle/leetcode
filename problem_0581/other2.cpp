class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mx=nums[0],r=-1,mn=nums[nums.size()-1],l=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mx)
                r=i;            
            mx=max(mx,nums[i]);
        }        
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>mn)
                l=i;            
            mn=min(mn,nums[i]);
        }
        return (r>l)? (r-l+1):0;
    }
};
