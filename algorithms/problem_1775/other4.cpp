class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {

        int bucket1[6] = {0}, bucket2[6] = {0}, nums1Sum = 0, nums2Sum = 0;
        for (int i = 0; i < nums1.size(); i++) bucket1[nums1[i] - 1]++, nums1Sum += nums1[i];
        for (int i = 0; i < nums2.size(); i++) bucket2[nums2[i] - 1]++, nums2Sum += nums2[i];

        // Greedy algorithm
        double diff = abs(nums1Sum - nums2Sum);
        int* pLargeBucket = nums1Sum >= nums2Sum ? &bucket1[0] : &bucket2[0];
        int* pSmallBucket = nums1Sum >= nums2Sum ? &bucket2[0] : &bucket1[0];
        for (int i = 5, j = 0, count = 0; i >= 1; i--, j++) {
            int n = pLargeBucket[i] + pSmallBucket[j];
            if (diff / i <= n) return count + ceil(diff / i);
            else diff = diff - n * i, count += n;
        }
        return -1;
    }
};
