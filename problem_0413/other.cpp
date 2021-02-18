class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(200000, 0);
        int i, res=0;

        for(i=2;i<A.size();i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i]=dp[i-1]+1;
                res +=dp[i];
            }
        }

        return res;
    }
};
