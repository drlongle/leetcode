class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int resultMax = INT_MIN, resultMin = INT_MAX;
        int curMax = 0, curMin = 0;
        for (int i = 0; i < nums.size(); i++) {
            curMax += nums[i];
            if (resultMax < curMax)
                resultMax = curMax;
            if (curMax < 0)
                curMax = 0;

            curMin += nums[i];
            if (curMin < resultMin)
                resultMin = curMin;
            if (curMin > 0)
                curMin = 0;
        }
        return max(resultMax, abs(resultMin));
    }
};
