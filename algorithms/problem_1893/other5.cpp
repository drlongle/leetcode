class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        int t=INT_MAX,p=INT_MIN;
        int i,j;
        vector<int> v(52);
        for(i=0;i<ranges.size();i++)
        {
            v[ranges[i][0]]++;
            v[ranges[i][1]+1]--;
        }
        for(i=1;i<51;i++)
            v[i]+=v[i-1];
        for(i=left;i<=right;i++)
        {
            if(v[i]<=0)
                return 0;
        }
        return 1;
    }
};
