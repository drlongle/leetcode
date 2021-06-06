class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>M;
        for(auto n:nums)
            M[n]++;

        int ans =0;
        for(auto n:nums)
        {
            if(M.find(n-1) != M.end())
                continue;
            else
            {
                int size = 1;
                int curr = n+1;
                while(M.find(curr) != M.end())
                {
                    curr++;
                    size++;
                }
                ans = max(ans, size);
            }
        }

        return ans;
    }
};
