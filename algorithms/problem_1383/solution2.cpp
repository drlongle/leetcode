class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long sum = 0, res = 0, MOD = 1000000007, cnt = 0;
        map<int, vector<int>> levels;
        multiset<int, greater<>> nums, taken;
        for (int i = 0; i < n; ++i) {
            levels[efficiency[i]].push_back(speed[i]);
            nums.insert(speed[i]);
        }

        while (levels.size()) {
            while (cnt < k  && nums.size()) {
                auto itr = nums.begin();
                sum += *itr;
                nums.erase(itr);
                ++cnt;
            }
            res = max(res, sum * levels.begin()->first);

            auto it = levels.begin();
            for (int i: it->second) {
                auto itr = nums.find(i);
                if (itr != nums.end()) {
                    nums.erase(itr);
                } else {
                    sum -= i;
                    --cnt;
                }
            }
            levels.erase(it);
        }

        return res % MOD;
    }
};