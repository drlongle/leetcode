class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1, i1 = m-1, i2 = n-1;
        while (i1 >= 0 && i2 >= 0) {
            nums1[i--] = (nums1[i1] > nums2[i2]) ? nums1[i1--] : nums2[i2--];
        }
        if (i2 >= 0)
            memcpy(&nums1[0], &nums2[0], (i2+1)*sizeof(int));
    }
};
