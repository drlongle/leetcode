class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numsSize = nums.size();
        int count = 0;
        int result = 0;
        int zeroIndex = -1;
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i])
            {
                count++;
            }
            else
            {
                result = max(result, count);
                count = i - zeroIndex;
                zeroIndex = i;
            }
        }

        return max(result, count);;
    }
};
