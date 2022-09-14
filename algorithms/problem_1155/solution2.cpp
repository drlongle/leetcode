class Solution {
  public:
    int numRollsToTarget(int n, int k, int target) {
        map<int, int> cnt, dup;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            dup.clear();
            for (auto &[key, v] : cnt) {
                for (int j = 1; j <= k; ++j) {
                    dup[key + j] = (v + dup[key + j]) % 1000000007;
                }
            }
            swap(cnt, dup);
        }
        return cnt[target];
    }
};
