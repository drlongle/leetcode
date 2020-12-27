class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int score = nums[0];
        deque<pair<int, int>> dq;
        dq.push_back({0, score});
        for (int i = 1; i < n; i++) {
            // pop the old index
            while (!dq.empty() && dq.front().first < i - k) {
                dq.pop_front();
            }
            score = dq.front().second + nums[i];
            while (!dq.empty() && score >= dq.back().second) {
                dq.pop_back();
            }
            dq.push_back({i, score});
        }
        return score;
    }
};