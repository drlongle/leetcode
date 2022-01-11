class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        score[0] = nums[0];
        priority_queue<pair<int, int>> priorityQueue;
        priorityQueue.push({nums[0], 0});
        for (int i = 1; i < n; i++) {
            // pop the old index
            while (priorityQueue.top().second < i - k) {
                priorityQueue.pop();
            }
            score[i] = nums[i] + score[priorityQueue.top().second];
            priorityQueue.push({score[i], i});
        }
        return score[n - 1];
    }
};
