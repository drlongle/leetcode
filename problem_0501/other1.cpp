class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        priority_queue<int> q1;
        priority_queue<int,vector<int>,greater<int>>q2;
        int i,n=nums.size(),j;
        for(i=0;i<n;i++){
            q1.push(nums[i]);
            q2.push(nums[i]);
        }
        for(i=0;i<n;i++){
            if(nums[i]!=q2.top())
                break;
            q2.pop();
        }
        if(i==n)
            return 0;
        for(j=n-1;j>=0;j--){
            if(nums[j]!=q1.top())
                break;
            q1.pop();
        }
        return j-i+1;
    }
};
