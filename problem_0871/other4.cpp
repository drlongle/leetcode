class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target,0});
        int ret=0;
        priority_queue<int>q;
        for(auto &x:stations)
        {
            while(startFuel<x[0] && q.size()!=0)
            {
                startFuel+=q.top();
                q.pop();
                ret++;
            }
            if(startFuel<x[0] && q.size()==0 )
                return -1;
            q.push(x[1]);
        }
        return ret;
    }
};
