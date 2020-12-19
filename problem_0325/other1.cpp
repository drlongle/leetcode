class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> cSums;
        int cSum = 0;
        int max_size = INT32_MIN;

        // Add an entry for prefix sum '0' in the HashTable with a index '-1'
        // This will help in finding the subarray when we encounter a prefix sum that's same as 'k'
        cSums[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            cSum += nums[i];

            if (cSums.count(cSum - k)) {
                max_size = max(max_size, i - cSums[cSum - k]);
            }

            if (!cSums.count(cSum))
                // Add the index only for the first time to get max-size subarray
                cSums[cSum] = i;
                // Note - Keep updating each time the same entry is found to get min-size subarray
        }

        return (max_size == INT32_MIN ? 0 : max_size);
    }
};
