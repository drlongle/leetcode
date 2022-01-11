class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n <= 0) return;
        int idx = nums1.size() - 1;
        int idx1 = m - 1;
        int idx2 = n - 1;
        while (idx >= 0) {
            if (idx2 < 0 or (idx1 >= 0 and nums1[idx1] > nums2[idx2])) {
                nums1[idx--] = nums1[idx1--];
            }
            else {
                nums1[idx--] = nums2[idx2--];
            }
        }
    }
};

