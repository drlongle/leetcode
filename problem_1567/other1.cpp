class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i=0, j=0;
        int n= nums.size();
        int len=0;
        int prod=1;
        while(i<n)
        {
            if(nums[i]==0)
            {
                while(j<i)
                {
                    prod/=(nums[j]>0)?1:-1;
                    if(prod>0)
                        len = max(len, i-j-1);
                    j++;
                }
                j=i+1;
            }
            else
            {
                prod*=(nums[i]>0)?1:-1;
                if(prod>0)
                {
                    len= max(len, i-j+1);
                }
            }
            i++;
        }

        while(j<i)
        {
            prod/=nums[j]>0?1:-1;
            if(prod>0)
                len = max(len, i-j-1);
            j++;
        }
        return len;
    }
};
