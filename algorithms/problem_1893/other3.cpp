class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        map<int,int>mp;
        int min_e = 1e5,max_e = -999;
        for(int i = 0;i<ranges.size();i++){
            int l = ranges[i][0],r = ranges[i][1];
            for(int j = l;j<=r;j++)
                mp[j]++;
        }
        for(int i = left;i<=right;i++)
            if(mp[i] == 0)return false;
        return true;
    }
};
