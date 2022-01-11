class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& prs) {
        vector<int>v(n);
        for(vector<int>vx:prs)//store the current assigned pair
        {
            v[vx[0]]=vx[1];
            v[vx[1]]=vx[0];
        }
        int res=0;  //to store result
        for(int i=0;i<n;i++)    //start from 0 iterate through every point
        {
            int x=0;
            for(int j=0;j<pref[i].size();j++)    // iterate through its pref.
            {
                if(pref[i][j]==v[i])break; // if we reach current assigned value then i is happy no need to check further

                for(int k=0;k<pref[pref[i][j]].size();k++)  //iterate through pref. of pref[i][j] to check if we reach i before reaching assigned value of pref[i][j]
                {
                    if(pref[pref[i][j]][k]==i) // if we reach i for any value in pref list before its assigned we find its unhappy couple.
                    {x++;break;}
                    if(pref[pref[i][j]][k]==v[pref[i][j]]) // if we reach assigned pair before reaching i the this value in pref of i is happy
                        break;
                }
                if(x)break;  //we find a pair for i no need to check further
            }
            res+=x; // increment the result
        }
        return res;
    }
};
