class Solution {
public:
    using ll = long long;
    int getMaxLen(vector<int>& nums) {
        ll i, n=nums.size(), ans=0;
        vector<ll> pos(n), neg(n);
        pos[0]=nums[0]>0 ? 1 : 0;
        neg[0]=nums[0]<0 ? 1 : 0;
        ans=pos[0];
        for(i=1; i<n; i++){
            if(nums[i]>0){
                pos[i]=1+pos[i-1];
                neg[i]=neg[i-1]>0 ? 1+neg[i-1]:0;
            }
            else if(nums[i]<0){
                pos[i]=neg[i-1]>0 ? 1+neg[i-1] : 0;
                neg[i]=1+pos[i-1];
            }
            ans=max(ans, pos[i]);
        }
        return ans;
    }
};
