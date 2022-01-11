class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0;
        int currentSum = 0;
        unordered_set<int> set;
        int start = 0;
        for (int end = 0; end < nums.size(); end++) {
            // increment start until subarray has unique elements
            while (set.find(nums[end]) != set.end()) {
                set.erase(nums[start]);
                currentSum -= nums[start];
                start++;
            }
            currentSum += nums[end];
            set.insert(nums[end]);
            // update result with maximum sum found so far
            result = max(result, currentSum);
        }
        return result;
    }
};