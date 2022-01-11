class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> lookup;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < m; ++i) {
            lookup[nums1[i]].push_back(i);
        }

        int res = 0;
        for (int j = 0; j < n; ++j) {
            if (j + res >= n)
                break;
            vector<int>& pos = lookup[nums2[j]];
            for (int i: pos) {
                if (i + res >= m)
                    break;
                int k = j, run = 0;
                while (i < m && k < n) {
                    if (nums1[i++] != nums2[k++])
                        break;
                    ++run;
                }
                res = max(res, run);
            }
        }
        return res;
    }
};