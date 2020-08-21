class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {

        vector<int>arr(A.size()+1,0);
        int n=A.size();

        for(int i=1;i<=n;i++){
            int curr=INT_MIN;
            for(int j=i-1;j>=i-K&&j>=0;j--){
                curr=max(curr,A[j]);
                arr[i]=max(arr[i],arr[j]+curr*(i-j));
            }
        }

        return arr[n];
    }
};
