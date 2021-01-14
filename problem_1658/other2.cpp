class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum=accumulate(begin(nums), end(nums), 0);
        int temp = sum-x;
        if(temp<0){
            return -1;
        }
        int i=0,j=0,sz=numeric_limits<int>::min();
        int cursum=0;
        while(i<n&&j<n){
            if(cursum<temp){
                cursum+=nums[j];
                j++;
            }
            else if(cursum>temp){
                cursum-=nums[i];
                i++;
            }
            if(cursum==temp){
                sz = max(j-i,sz);
                if(j==n){
                    break;
                }
                cursum+=nums[j];
                j++;
            }
        }
        return sz==numeric_limits<int>::min()?-1:n-sz;
    }
};
