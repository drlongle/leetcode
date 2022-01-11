class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> countMap(10001, 0);
        int start = 0;
        int result = 0;
        int currentSum = 0;
        for (int end = 0; end < nums.size(); end++) {
            int currentElement = nums[end];
            countMap[currentElement]++;
            currentSum += currentElement;
            while (start < end && countMap[currentElement] > 1) {
                countMap[nums[start]]--;
                currentSum -= nums[start];
                start++;
            }
            // update result with maximum sum found so far
            result = max(result, currentSum);
        }
        return result;
    }
};
