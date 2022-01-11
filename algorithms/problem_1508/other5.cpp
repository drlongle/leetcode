class Solution {
public:
#define maxv 100
#define MOD 1000000007

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans=(solve(nums,right)-solve(nums,left-1))%MOD;
        if(ans<0)  ans+=MOD;
        return ans;
    }
    
    int solve(vector<int>& v, int position){
     // find the sum of subarrays for that sum is at <=position in the sorted array
        if(position<1)return 0;
        
        int sum=bsearch(v, position);
        int ans=0;
        int s=0;
        int n=v.size();
        
        int count=0;
        
        vector<int> mult_sums(n),prefix_sums(n);
        prefix_sums[0]=v[0];
        mult_sums[0]=v[0];
        for(int i=1;i<n;i++){
            prefix_sums[i]=(prefix_sums[i-1]+v[i])%MOD;
            mult_sums[i]=(mult_sums[i-1]+(i+1)*v[i])%MOD;
        }
            
        for(int start=0,end=0;end<n;end++){
            s+=v[end];
            for(;start<=end&&s>sum;start++)
                s-=v[start];
            
            count+=end-start+1;
            
            if(start<=end){
                ans+=mult_sums[end]-(start==0?0:mult_sums[start-1]);
                if(start>0) ans-=((long) start*(prefix_sums[end]-prefix_sums[start-1]))%MOD;
                ans%=MOD;
            }
        }
        ans-=((long) (count-position)*sum)%MOD;
        ans%=MOD;
        if(ans<0) ans+=MOD;
        
        return ans;
    }
    
    int bsearch(vector<int>& v, int position){
    // return the position-th number in the sorted sequence
        int n=v.size();
        int low=0;
        int high=maxv*n;
        
        while(low<high){
            int mid=(low+high)/2;

            if(count_subarary_with_target(v,mid)<position) low=mid+1;
            else high=mid;
        }
        return low;
    }
    
    int count_subarary_with_target(vector<int>& v, int target){
        
        int n=v.size();
        int s=0;
        int count=0;
        for(int start=0,end=0;end<n;end++){
           s+=v[end];
           for(;start<=end&&s>target;start++)
               s-=v[start];
                
           count+=end-start+1;
        }
        return count;
    }
};
