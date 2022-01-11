class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start =0;
        int end = 0;
        int res = 0 ;
        int Wincount = 0;
        while(end<size(nums))
        {
            if(nums[end] >= left && nums[end] <=right)
                Wincount = end -start +1;
            else if(nums[end]> right)
                start = end+1, Wincount = 0;

            res += Wincount;
            end++;
        }
        return res;
    }
};