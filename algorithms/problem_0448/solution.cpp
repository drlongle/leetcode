class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int num = abs(nums[i]);
            int index = num - 1;
            nums[index] = -abs(nums[index]);
        }

        vector<int> res;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
