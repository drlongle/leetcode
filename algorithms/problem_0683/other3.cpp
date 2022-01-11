class Solution {
public:
    struct bucket{
        int min = INT_MAX;
        int max = INT_MIN;
    };

    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        int nBucket = n/(k+1);
        if(n%(k+1)) nBucket++;
        bucket cur;
        vector<bucket> dp(nBucket,cur);
        int iBucket;
        bool updatemin,updatemax;
        for(int i=0; i<n; i++){
            iBucket = bulbs[i]/(k+1);
            updatemin = updatemax = false;
            if(bulbs[i]%(k+1)) iBucket++;
            if(bulbs[i]>dp[iBucket-1].max){
                updatemax = true;
                dp[iBucket-1].max = bulbs[i];
            }
            if(bulbs[i]<dp[iBucket-1].min){
                updatemin = true;
                dp[iBucket-1].min = bulbs[i];
            }
            // right
            if(updatemax && iBucket<nBucket && dp[iBucket-1].max+k+1==dp[iBucket].min) return i+1;
            // left
            if(updatemin && iBucket>1 && dp[iBucket-1].min-k-1==dp[iBucket-2].max) return i+1;
        }
        return -1;
    }
};
