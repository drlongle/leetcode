class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> output;
        int remain_void = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            while (!output.empty() && output.back() > nums[i] &&
                   remain_void > 0) {
                output.pop_back();
                remain_void--;
            }
            output.push_back(nums[i]);
        }
        output.resize(k);
        return output;
    }
};
