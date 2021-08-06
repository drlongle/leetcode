class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<int> Fuels;
        stations.push_back({target,0});
        int max_reachable=startFuel,ans=0;
        for(int i=0;i<stations.size();i++){
            while(!Fuels.empty() and max_reachable<stations[i][0]){
                ans++;
                max_reachable+=Fuels.top();
                Fuels.pop();
            }
            if(max_reachable<stations[i][0])
                return -1;
            Fuels.push(stations[i][1]);
        }
        return ans;
    }
};
