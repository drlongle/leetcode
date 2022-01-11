class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0)
            return k;

        int i = 1;
        for (; i < n && k > 0; ++i)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff > 1)
            {
                if (diff <= k)
                    k -= (diff - 1);
                else
                    return nums[i - 1] + k;
            }
        }

        return nums[i - 1] + k;
    }
};
