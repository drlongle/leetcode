class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> tail_values;
    
    for (const auto& n: nums)
    {
        auto it = lower_bound(tail_values.begin(), tail_values.end(), n);
        if (it == tail_values.end())
            tail_values.emplace_back(n);
        else
            *it = n;
    }

    return tail_values.size();
  }
};

