class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int i=0,j=0,res=0;
        while(j<nums.size()){
            if(nums[j]==0)
                zero++;
            if(zero>1){
                while(nums[i++]!=0);
                zero--;
            }
            res=max(res,j-i); // we don't write j-i+1 because we need to give its length after removing the zero
            j++;
        }
        return res;
    }
};
