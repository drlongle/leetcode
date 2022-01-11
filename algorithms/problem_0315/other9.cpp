class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = 2e4+10;
        vector<int> bits(N);
        auto lsb = [](int x) {
            return x & -x;
        };
        auto update = [&](int i, int cnt) {
            while(i < N) {
                bits[i] += cnt;
                i += lsb(i);
            }
        };

        auto get = [&](int i) {
            int ret = 0;
            while(i > 0) {
                ret += bits[i];
                i -= lsb(i);
            };
            return ret;
        };

        vector<int> ret(nums.size());
        for(int i=nums.size()-1; i>=0; --i) {
            int cur = nums[i] + 1e4+1;
            ret[i] = get(cur-1);
            update(cur, 1);
        }
        return ret;
    }
};