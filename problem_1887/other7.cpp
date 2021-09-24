class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> v(5 * 10000 + 1, 0);
        for (int i : nums) {
            v[i]++;
        }
        int ops = 0, sum = 0;
        for (int i = v.size() - 1; i > 0; i--) {
            if (v[i] != 0) {
                sum += v[i];
                ops += sum;
            }
        }
        return ops - sum;
    }
};
