class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int start = 0;
        for(const auto &group : groups) {
            int n = group.size();
            unordered_map<int, int> dict;
            for (int i = 0; i < n; ++i) {
                dict[group[i]] = n - i;
            }

            while (!cmp(group, nums, start, n)) {
                if (start + n >= nums.size()) {
                    return false;
                }
                if (dict.find(nums[start + n]) != dict.end()) {
                    start += dict[nums[start + n]];
                } else {
                    start += n;
                }
            }
            start += n;
        }
        return true;
    }

    bool cmp(const vector<int> &group, const vector<int> &nums, int start, int n) {
        if (start + n > nums.size()) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (group[i] != nums[start + i]) {
                return false;
            }
        }
        return true;
    }
};
