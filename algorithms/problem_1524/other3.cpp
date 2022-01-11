/*
For every index count the number of subarrays such that sum is odd and ending with current element
    Odd+Even=Odd
    Even+Odd=Odd
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int MOD=1000000007;
        int n=nums.size();
        if(n==0)return 0;
        
        long long pre_sum=0;
        int  odd_sum_count=0;
        int even_sum_count=0;
        int ans=0;
        // for single number subset to be counted if it is odd 
        even_sum_count=1;
        
        for(int i=0;i<n;++i){
            
            pre_sum+=nums[i];
            if(pre_sum % 2==0){
                ans+=odd_sum_count;
                even_sum_count++;
            }
            else{
                ans+=even_sum_count;
                odd_sum_count++;    
            }
            ans=ans%MOD;
        }
        return ans;
        
    }
};
