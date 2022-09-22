class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        map<int, int> cnt;
        for (int n : nums)
            ++cnt[n];
        vector<int> res;
        for (auto [k, v] : cnt)
            if (v > nums.size() / 3)
                res.push_back(k);
        return res;
    }
};
