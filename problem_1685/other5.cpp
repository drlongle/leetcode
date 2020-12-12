class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(nums[i]-nums[0]);;
        }
        vector<int>res(n);
        res[0]=sum;
        for(int i=1;i<n;i++){
            int t=sum+(nums[i]-nums[i-1])*i;
            t-=(nums[i]-nums[i-1])*(n-i);
            sum=res[i]=t;
        }
        return res;
    }
};
