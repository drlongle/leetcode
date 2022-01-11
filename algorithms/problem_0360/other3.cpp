class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            nums[i] = a*pow(nums[i], 2)+b*nums[i]+c;
        if(a>0)
        {
            int p1 = 0;
            int p2 = nums.size()-1;
            while(p1<=p2)
            {
                if(nums[p1]>nums[p2])
                    ans.push_back(nums[p1++]);
                else
                    ans.push_back(nums[p2--]);
            }
            reverse(ans.begin(), ans.end());
        }
        else
        {
            int p1 = 0;
            int p2 = nums.size()-1;
            while(p1<=p2)
            {
                if(nums[p1]<nums[p2])
                    ans.push_back(nums[p1++]);
                else
                    ans.push_back(nums[p2--]);
            }
        }
        return ans;
    }
};
