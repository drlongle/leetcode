class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    set<int> tail_values;
    
    for (const auto n: nums)
    {
        auto it = tail_values.lower_bound(n);
        if (it != tail_values.end())
            tail_values.erase(it);
        tail_values.emplace(n);
    }

    return tail_values.size();
  }
};

