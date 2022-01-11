class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0),cs=0,n=nums.size();
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                vec.push_back(s-(n*nums[i]));
            else {
                cs+=nums[i-1];
                vec.push_back(nums[i]*i - cs + s - cs - (n-i)*nums[i]);
            }
        }
        return vec;
    }
};
