class Solution {
  public:
    bool judgePoint24(vector<int> &cards) {

        function<bool(vector<double> &)> fn = [&](vector<double> &nums) {
            if (nums.size() == 1)
                return abs(nums[0] - 24) < 1e-6;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    vector<double> cand;
                    for (int k = 0; k < nums.size(); ++k)
                        if (k != i && k != j)
                            cand.push_back(nums[k]);
                    vector<double> vals = {nums[i] + nums[j], nums[i] - nums[j],
                                           nums[j] - nums[i],
                                           nums[i] * nums[j]};
                    if (nums[j])
                        vals.push_back(nums[i] / nums[j]);
                    if (nums[i])
                        vals.push_back(nums[j] / nums[i]);
                    for (auto &x : vals) {
                        cand.push_back(x);
                        if (fn(cand))
                            return true;
                        cand.pop_back();
                    }
                }
            }
            return false;
        };

        vector<double> nums(cards.begin(), cards.end());
        return fn(nums);
    }
};
