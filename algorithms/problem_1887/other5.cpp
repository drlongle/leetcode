class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int res=0;
        int j=0;
        while(j<nums.size())
        {
            if(nums[0]!=nums[j])
            {
                nums[0]=nums[j];
                res+=j-0;
            }
            j++;
        }
        return res;
    }
};
