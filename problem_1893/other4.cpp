class Solution {
public:
    bool isCovered(vector<vector<int>>& ran, int l, int r) {
        sort(ran.begin(),ran.end());
        if(ran[0][0]>l)
            return false;
        int i=0;
        while(i<ran.size()&&l<=r)
        {
            if(l<ran[i][0])
                return false;
            else if(ran[i][1]>=l)
                l=ran[i][1]+1;
            i++;
        }
        if(l<=r)
            return false;
        return true;
    }
};
