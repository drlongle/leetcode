typedef long long int ll;
ll mod=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n=A.size();
        stack<int> s1,s2;
        ll ans=0;
        vector<int> next_small(n),pre_small(n);

        for(int i=0;i<n;i++){
            pre_small[i]=i;
            next_small[i]=n-1-i;
        }

        for(int i=0;i<n;i++){
            while(!s1.empty() && A[s1.top()]>A[i]){
                next_small[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && A[s2.top()]>=A[i]){
                pre_small[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }

        for(int i=0;i<n;i++){
            ans+=A[i]*(pre_small[i]+1)*(next_small[i]+1);
            ans%=mod;
        }

        return ans;
    }
};

