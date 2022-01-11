class Solution {
private:
    vector<int>subset;
    vector<vector<int>>res;
public:
    void backtrack(int n,int start)
    {
        if(n<=1 and subset.size()>1)
        {
            res.push_back(subset);
            return;
        }
        for(int i=start;i<=n;i++)
        {
            if(n%i==0)
            {
                subset.push_back(i);
                backtrack(n/i,i);
                subset.pop_back();
            }
        }

    }
    vector<vector<int>> getFactors(int n) {
        backtrack(n,2);
        return res;
    }
};
