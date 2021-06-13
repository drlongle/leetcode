class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {     // backtracking with distance cache and

        const int W = workers.size();
        const int B = bikes.size();

        // pre-compute all distances and put them in the cache
        vector<vector<int>> distCache (W,vector<int>(B,0));
        for (auto w=0; w<W; w++) {
            for (auto b=0; b<B; b++) {
                distCache[w][b]=abs(workers[w][0]-bikes[b][0]) + abs(workers[w][1]-bikes[b][1]);
            }
        }

        // map, taken_bikes_mask:distance, mask 0000101 means 0 and 2 bikes are taken
        vector<int> memo (1<<B,-1);

        // recursive lambda
        function<int(int,int)>
                bt {[&](int wid, int bikeMask) {

            if (wid==W) {
                return 0;
            }

            if (memo[bikeMask]>=0)
                return memo[bikeMask];

            int min_sum=INT_MAX;

            for (auto b=0; b<B; b++) {
                if (1<<b & bikeMask) continue;
                auto sum = distCache[wid][b] + bt(wid+1, (1<<b) | bikeMask);
                min_sum=min(min_sum,sum);
            }

            memo[bikeMask]=min_sum;

            return min_sum;
        }};

        // call
        return bt(0,0);
    }
};
