class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n: nums) {
            x ^= n;
        }
        int y = x & (~(x - 1));
        vector<int> res(2, 0);
        for (int n: nums) {
            if (n & y)
                res[0] ^= n;
        }
        res[1] = x ^ res[0];

        return res;
    }
};
