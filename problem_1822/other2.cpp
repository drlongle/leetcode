class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int ans = 1;
        for(int i : nums)
        {
            if(i < 0)
                ans *= -1;
            if(i == 0)
                return 0;
        }
        return ans;
    }
};
