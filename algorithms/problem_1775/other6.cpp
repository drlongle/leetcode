class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n && (m > n * 6)) return -1;
        if (m < n && (n > m * 6)) return -1;
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0), sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) return 0;
        // Swap
        if (sum1 > sum2) return minOperations(nums2, nums1);
        // Increase
        sort(nums1.begin(), nums1.end());
        // Decrease
        sort(nums2.rbegin(), nums2.rend());
        int cnt = 0;
        // Break the for-loop when sum1 >= sum2
        for (int i = 0, j = 0; sum1 < sum2;) {
            // Change the number which provide max diff
            int d1 = i == m ? 0 : 6 - nums1[i];
            int d2 = j == n ? 0 : nums2[j] - 1;
            if (d1 > d2) {
                sum1 += d1;
                ++cnt;
                ++i;
            } else {
                sum2 -= d2;
                ++cnt;
                ++j;
            }
        }
        return cnt;
    }
};
