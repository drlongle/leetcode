class Solution {
  public:
    int numOfPairs(vector<string> &nums, string target) {
        int sz = nums.size(), res = 0;
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j) {
                if (i != j && nums[i] + nums[j] == target)
                    ++res;
            }
        return res;
    }
};
