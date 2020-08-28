class Solution {
#define ll long long int
public:
    int findLatestStep(vector<int>& a,int m) {ll n=a.size(),i,ans=-1;
        vector<int> dp(n+1),l(n+1),r(n+1),cnt(n+1);
        for(i=0;i<n;i++)
        {
            dp[a[i]]=1+(a[i]>1?dp[a[i]-1]:0)+(a[i]<n?dp[a[i]+1]:0);l[a[i]]=r[a[i]]=a[i];
            cnt[dp[a[i]]]++;
            if(a[i]>1&&dp[a[i]-1])
            {
                cnt[dp[a[i]-1]]--;
                l[a[i]]=l[a[i]-1];
                dp[l[a[i]]]=dp[a[i]];
            }
            if(a[i]<n&&dp[a[i]+1])
            {
                cnt[dp[a[i]+1]]--;
                r[a[i]]=r[a[i]+1];
                dp[r[a[i]]]=dp[a[i]];
            }
            if(a[i]>1&&dp[a[i]-1])
                r[l[a[i]-1]]=r[a[i]];
            if(a[i]<n&&dp[a[i]+1])
                l[r[a[i]+1]]=l[a[i]];
            if(cnt[m])
                ans=i+1;
        }return ans;
    }
};