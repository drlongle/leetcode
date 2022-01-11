class Solution {
public:
    int getMaxLen(std::vector<int>& nums) {
        int min_neg_len = 0, max_pos_len = 0;  // record the max length with positive product and negetive product
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                min_neg_len = max_pos_len = 0;
            } else if (nums[i] > 0) {
                if (min_neg_len > 0) min_neg_len++;
                max_pos_len++;
            } else {
                int tmp_neg = min_neg_len, tmp_pos = max_pos_len;
                min_neg_len = tmp_pos + 1;
                if (tmp_neg > 0) max_pos_len = tmp_neg + 1;
                else max_pos_len = 0;
            }
            res = std::max(max_pos_len, res);
        }
        return res;
    }
};