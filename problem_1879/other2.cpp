class Solution {
public:
    int helper(vector<int> &nums1, vector<int>&nums2, int i) {
        if(i >= nums1.size()) {
            return 0;
        }

        int ans = INT_MAX;
        for(int j = 0; j < nums2.size(); j++) {
            if(nums2[j] != -1) {
                int t = nums2[j];
                int val = nums1[i]^nums2[j];
                nums2[j] = -1;
                ans = min(ans, helper(nums1, nums2, i+1) + val);
                nums2[j] = t;
            }
        }
        return ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2, 0);
    }
};
