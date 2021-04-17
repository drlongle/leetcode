class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {

        const int W = workers.size();
        const int B = bikes.size();

        struct Pair {
            int wid;
            int bid;
        };

        vector<vector<Pair>> distMap(2001); // for counting sort

        for (auto w=0; w<W; w++) {
            for (auto b=0; b<B; b++) {
                auto d=abs(workers[w][0]-bikes[b][0])+abs(workers[w][1]-bikes[b][1]);
                distMap[d].push_back({w,b});
            }
        }

        vector<int> w_b(W,-1);
        vector<bool> bikeTaken(B,false);
        for (auto &pairs : distMap) {
            for (auto [w,b] : pairs) {
                if (!bikeTaken[b] && w_b[w]<0) {
                    bikeTaken[b]=true;
                    w_b[w]=b;
                }
            }
        }

        return w_b;
    }
};
