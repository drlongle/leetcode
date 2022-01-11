class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> v, m;
        v.reserve(multipliers.size() + 2);
        v.emplace_back(0);
        m.reserve(multipliers.size() + 2);
        for(int j = 0; j < multipliers.size(); j++) {
            int mp = multipliers[j];
            m.resize(v.size() + 1);
            m[0] = INT_MIN;
            for(int i = 0; i < v.size(); i++) {
                m[i] = max(m[i], v[i] + mp * nums[nums.size() - 1 - (j - i)]);
                m[i + 1] = v[i] + mp * nums[i];
            }
            swap(m, v);
        }
        return *max_element(v.begin(), v.end());
    }
};
