class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<int> fuel;
        int cur = startFuel;
        int res = 0;
        int s = 0;
        while(cur < target)
        {
            while(s < stations.size() && cur >= stations[s][0])
            {
                fuel.push(stations[s++][1]);
            }

            if(fuel.empty())
                return -1;

            cur += fuel.top(); fuel.pop();
            res++;
        }
        return res;
    }
};
