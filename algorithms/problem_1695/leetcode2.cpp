class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0;
        int currentSum = 0;
        bool isPresent[10001]= {0};
        int start = 0;
        for (int end = 0; end < nums.size(); end++) {
            // increment start until subarray has unique elements
            while (isPresent[nums[end]]) {
                isPresent[nums[start]] = false;
                currentSum -= nums[start];
                start++;
            }
            isPresent[nums[end]] = true;
            currentSum += nums[end];
            // update result with maximum sum found so far
            result = max(result, currentSum);
        }
        return result;
    }
};