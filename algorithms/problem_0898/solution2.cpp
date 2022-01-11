class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> all;
        deque<int> prev, curr;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            int n = nums[i];
            if (i > 0 && n == nums[i-1])
                continue;
            for (int index = prev.size() - 1; index >= 0; --index) {
                int t = n | prev[index];
                curr.emplace_front(t);
                all.insert(t);
                if (prev[0] == prev[index])
                    break;
            }
            curr.push_back(n);
            all.insert(n);
            swap(prev, curr);
            curr.clear();
        }
        return all.size();
    }
};