class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &ar,int k)
    {
        int n=ar.size(),m=ar[0].size(),ans=INT_MIN;
        for(int j1=0;j1<m;j1++){
            vector<int> preSum(n,0);   //  preSum[i]->ar[i][j1]+~+ar[i][j2]
            for(int j2=j1;j2<m;j2++){
                set<int> st;
                st.insert(0);
                int cur=0;
                for(int i=0;i<n;i++){
                    cur+=ar[i][j2];
                    preSum[i]+=cur;
                    auto it=st.lower_bound(preSum[i]-k);
                    if(it!=st.end()) ans=max(ans,preSum[i]-*(it));
                    st.insert(preSum[i]);
                }
            }
        }
        if(ans!=INT_MIN) return ans;
        return -1;
    }
};
