class Solution {
public:
    int rob(vector<int>& nums) {
        int robMax = 0, skipMax = 0;
        for (int n : nums) {
            int rr = robMax, ss = skipMax;
            robMax = ss + n;   // rob this house
            skipMax = max(rr, ss); // skip this house
        }
        return max(robMax, skipMax);
    }
};

