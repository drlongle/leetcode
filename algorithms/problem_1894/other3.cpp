class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();

        vector<long long>prefix(n); // To store prefix sum
        prefix[0]=chalk[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+chalk[i]; // calculating prefix sum

        k%=prefix[n-1];
        // find the index with element strictly greater than k
        int pos=upper_bound(prefix.begin(),prefix.end(),k)-prefix.begin();
        return pos;
    }
};
