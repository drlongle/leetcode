class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        unordered_map<int,int>::iterator end=mp.end();
        int n=arr.size();
        long long int dp[n];
        long long int count1=0;
        for(int i=0;i<n;i++)
        {
            int j=i-1;
            dp[i]=1;
            mp.insert({arr[i],i});
            while(j>=0)
            {
                if(arr[i]%arr[j]==0)
                {
                    auto find1=mp.find(arr[i]/arr[j]);
                    if(find1!=end)
                        dp[i]+=(dp[j]*dp[find1->second]);
                }
                j--;
            }
            count1+=dp[i];
        }

        return count1%1000000007;
    }
};