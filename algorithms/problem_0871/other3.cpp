class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int , vector<int >> pq;
        int cnt = 0;

        for(int i = 0; i < stations.size(); i++) {
            if(startFuel >= target)
                return cnt;
            while(startFuel < stations[i][0]) {
                if(pq.empty())
                    return -1;
                startFuel += pq.top();
                pq.pop();
                cnt++;
            }
            pq.push(stations[i][1]);

        }

        while(!pq.empty() && startFuel < target) {
            startFuel += pq.top();
            pq.pop();
            cnt++;
        }

        if(startFuel < target)
            return -1;

        return cnt;
    }
};
