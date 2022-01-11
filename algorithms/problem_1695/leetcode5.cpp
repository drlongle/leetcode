class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastIndexes(10001, -1);
        int prefixSum[n + 1];
        int result = 0, start = 0;
        for (int end = 0; end < n; end++) {
            int currentElement = nums[end];
            prefixSum[end + 1] = prefixSum[end] + currentElement;
            if (lastIndexes[currentElement] != -1) {
                start = max(start, lastIndexes[currentElement] + 1);
            }
            // update result with maximum sum found so far
            result = max(result, prefixSum[end + 1] - prefixSum[start]);
            // update last index of current element
            lastIndexes[currentElement] = end;
        }
        return result;
    }
};