class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long oneSum = 0;
        for(auto v: arr){
            oneSum += v;
        }
        long long ans = 0;
        int len = arr.size();
        
        // left + allMid + right
        if(oneSum > 0 && k >= 2){
            long long leftAns = 0;
            long long rightAns = 0;
            
            long long tmpAns = 0;
            for(int i=0;i<len;i++){
                tmpAns += arr[i];
                leftAns = max(leftAns, tmpAns);
            }
            
            tmpAns = 0;
            for(int i=len-1;i>=0;i--){
                tmpAns += arr[i];
                rightAns = max(rightAns, tmpAns);
            }
            
            ans = max(ans, leftAns + rightAns + (k-2) * oneSum);
        }
        
        //left + right
        if(k > 1){
            for(int i=0;i<len;i++){
                arr.push_back(arr[i]);
            }
        }
        long long tmpAns = 0;
        for(auto v: arr){
            tmpAns += v;
            ans = max(ans, tmpAns);
            if(tmpAns < 0){
                tmpAns = 0;
            }
        }
        
        long long mod = 1000000007;
        return ans%mod;
    }
};
