/*
 We all know how to find all arrays that sum to a target in O(n) - track prefix sum in a hash map
 and look up complements (sum - target) there.

 Now, how do we count non-overlapping arrays? The intuition here is that the right side of our
 array is only increasing, and we can greedily track the smallest right. Value in dp is the left index
 of the subarray with the target sum. If we find a non-overlapping array (right <= left), we increase
 cnt and update right to the current position.
 */

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = -1;
        int sum = 0, right = -1, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (dp.count(sum - target)) {
                int left = dp[sum - target];
                if (right <= left) {
                    ++cnt;
                    right = i;
                }
            }
            dp[sum] = i;
        }
        return cnt;
    }
};