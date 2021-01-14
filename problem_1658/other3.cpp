class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> hash;

        int presum = 0;
        int i=1;
        hash[0]=0;

        for(auto &k: nums){
            presum+=k;
            hash[presum] = i++;
        }

        int n = nums.size();
        int suSum = 0;
        int ans = numeric_limits<int>::max();
        int op = 0;

        if(hash.find(x)!=hash.end()){
            ans = min(ans,hash[x]);
        }

        for(i=n-1;i>=0;i--){
            suSum +=nums[i];
            ++op;
            if(hash.find(x-suSum)!=hash.end() && hash[x-suSum] <= i){
                ans = min(ans,hash[x-suSum] + op);
            }
        }

        return ans == numeric_limits<int>::max()? -1 : ans;
    }
};
