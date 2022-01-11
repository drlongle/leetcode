class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int MAX_DISTANCE = 2000;
        vector<vector<pair<int, int>>> buckets(MAX_DISTANCE + 1);
        int M = bikes.size();
        int N = workers.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                auto dist = distance(workers[i], bikes[j]);
                buckets[dist].push_back({i, j});
            }
        }

        vector<int> res(N, -1);
        vector<bool> usedBikes(M, false);

        for (int i = 1; i <= MAX_DISTANCE; i++) {
            for (const auto& [worker, bike] : buckets[i]) {
                if (res[worker] != -1 || usedBikes[bike]) {
                    continue;
                }
                usedBikes[bike] = true;
                res[worker] = bike;
            }
        }

        return res;
    }

private:
    int distance(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
