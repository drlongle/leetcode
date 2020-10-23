class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min_value = numeric_limits<int>::max();
        multiset<int> s(cbegin(nums), cend(nums));
        for (const auto val : nums) {
            s.erase(s.find(val));
            if (val > min_value) {
                auto it = s.upper_bound(min_value);
                if (it != cend(s) && *it < val) return true;
            };
            min_value = min(min_value, val);
        }
        return false;
    }
};