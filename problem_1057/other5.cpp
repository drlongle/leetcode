class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int W = workers.size(), B = bikes.size();

        auto cmp = [&] (const pair<int,int>& p1, const pair<int,int>& p2) {
            int dist1 = abs(workers[p1.first][0] - bikes[p1.second][0]) + abs(workers[p1.first][1] - bikes[p1.second][1]);
            int dist2 = abs(workers[p2.first][0] - bikes[p2.second][0]) + abs(workers[p2.first][1] - bikes[p2.second][1]);
            if (dist1 < dist2) return false;
            else if (dist1 == dist2 && p1.second < p2.second) return false;
            return true;
        };
        vector<priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>> workerBike;

        // W(BlogB) ==> WBlogB
        for (int w = 0; w < W; w++) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> PQ(cmp);
            workerBike.push_back(PQ);
            for (int b = 0; b < B; b++) {
                workerBike[w].push({w,b});
            }
        }

        auto cmp2 = [&] (const pair<int,int>& p1, const pair<int,int>& p2) {
            int dist1 = abs(workers[p1.first][0] - bikes[p1.second][0]) + abs(workers[p1.first][1] - bikes[p1.second][1]);
            int dist2 = abs(workers[p2.first][0] - bikes[p2.second][0]) + abs(workers[p2.first][1] - bikes[p2.second][1]);
            if (dist1 < dist2) return false;
            else if (dist1 == dist2 && p1.first < p2.first) return false;
            else if (dist1 == dist2 && p1.first == p2.first && p1.second < p2.second) return false;
            return true;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp2)> PQ2(cmp2);
        for (int w = 0; w < W; w++) {
            PQ2.push(workerBike[w].top());
            workerBike[w].pop();
        }

        vector<bool> visited(B, false);
        vector<int> res(W,-1);
        // WlogW
        while (!PQ2.empty()) {
            int w = PQ2.top().first;
            int b = PQ2.top().second;
            PQ2.pop();
            if (visited[b] == true) {
                PQ2.push(workerBike[w].top());
                workerBike[w].pop();
                continue;
            }
            visited[b] = true;
            res[w] = b;
        }
        return res;
    }
};
