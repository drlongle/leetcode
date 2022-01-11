class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size() , ret = 0;
        for (int i = 1-m; i < n; ++i) {
            int j = max(0, i) , k = max(0, -i) , l = 0;
            while (j < n && k < m) {
                l = nums1[j++] == nums2[k++] ? l+1 : 0;
                ret = max(ret, l);
            }
        }
        return ret;
    }
};
