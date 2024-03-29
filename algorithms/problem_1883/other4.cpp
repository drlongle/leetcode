class Solution {
public:

    int normalize(double a)
    {
        int ret=a;
        if(ret==a)
            return ret;
        else return ret+1;
    }
    double memo[1000][1000];
    int speed;
    double dp(int i,int skips,vector<int>& arr)
    {
        if(i<0)
            return 0;
        else if(memo[i][skips]!=0)
            return memo[i][skips];
        else {
            double t=(double)arr[i]/speed;
            double q=normalize((double)dp(i-1,skips,arr)+t);
            if(skips)
                q=min(q,(double)dp(i-1,skips-1,arr)+t-(1e-8));
            return memo[i][skips]=q;
        }
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) 
    {
        memset(memo,0,sizeof(memo));
        this->speed=speed;
        for(int skips=0;skips<dist.size();++skips)
            if(dp(dist.size()-1,skips,dist)<=hoursBefore)
                return skips;
        return -1;
    }
};
