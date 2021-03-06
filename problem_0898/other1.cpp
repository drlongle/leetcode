class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        vector<int> dp;
        unordered_set<int> unique;
        int i=0,j=0;
        for(auto elem: arr)
        {
            int newarray = dp.size();
            dp.push_back(elem);
            unique.insert(elem);
            for(int k = i; k<j; k++)
            {
                int temp = dp[k] | elem;
                if(temp>dp.back())
                {
                    dp.push_back(temp);
                    unique.insert(temp);
                }
            }
            i = newarray, j = dp.size();
        }

        return unique.size();
    }
};
