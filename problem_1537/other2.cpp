#define ll long long int

class Solution {
public:
    ll dfsit(int i,vector<ll> &dp,unordered_map<int,vector<int>> &mp){
        ll nxt=0;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(auto j:mp[i]){
            nxt=max(nxt,dfsit(j,dp,mp));
        }
        nxt+=i;
        dp[i]=nxt;

        return dp[i];
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>> mp;
        vector<ll> dp;
        int maxi=0;

        for(int i=0;i<nums1.size();i++){
            maxi=max(maxi,nums1[i]);
            if(i+1<nums1.size()){
                mp[nums1[i]].push_back(nums1[i+1]);}

        }
        for(int i=0;i<nums2.size();i++){
            maxi=max(maxi,nums2[i]);
            if(i+1<nums2.size()){
                mp[nums2[i]].push_back(nums2[i+1]);
            }
        }
        dp.resize(maxi+1,-1);

        return max(dfsit(nums2[0],dp,mp)%1000000007,dfsit(nums1[0],dp,mp)%1000000007);
    }
};