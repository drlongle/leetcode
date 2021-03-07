class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> v, m;
        v.reserve(multipliers.size() + 1);
        v.emplace_back(0);
        for(int j = 0; j < multipliers.size(); j++) {
            int mp = multipliers[j];
            int m_next = INT_MIN;
            for(int i = 0; i < v.size(); i++) {
                int vi = v[i];
                v[i] = max(m_next, vi + mp * nums[nums.size() - 1 - (j - i)]);
                m_next = vi + mp * nums[i];
            }
            v.resize(v.size() + 1);
            v.back() = m_next;
        }
        return *max_element(v.begin(), v.end());
    }
};
