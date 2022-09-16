class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int crct_pos = nums[i] - 1;
            if (nums[crct_pos] != nums[i])
                swap(nums[crct_pos], nums[i]);

            else
                i++;
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                res.push_back(i + 1);

        return res;
    }
};
