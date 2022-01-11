class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int> left;
        int sum=0;
        int i=-1;
        while(i<(n-1) && sum<=x){
            left[sum]=i;
            sum+=nums[i+1];
            i++;
        }

        int j=n;
        sum=0;
        int res=INT_MAX;

        while(j>0 && sum<=x){
            if(left.find(x-sum)!=left.end()){
                res=min(res,n-j+left[x-sum]+1);
            }
            sum+=nums[j-1];
            j--;
        }

        return res==INT_MAX?-1:res;
    }
};
