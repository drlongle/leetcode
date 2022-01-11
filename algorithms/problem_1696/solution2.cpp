class Solution {
public:
    struct Entry {
        int val, ts;
        Entry(int v, int t): val(v), ts(t) {}
    };

    int maxResult(vector<int>& nums, int k) {
        deque<Entry> dq;
        int val = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            while (dq.size() && dq.front().ts < i - k)
                dq.pop_front();
            val = nums[i] + (dq.empty() ? 0 : dq.front().val);
            while (dq.size() && dq.back().val < val)
                dq.pop_back();
            dq.emplace_back(val, i);
        }
        return val;
    }
};