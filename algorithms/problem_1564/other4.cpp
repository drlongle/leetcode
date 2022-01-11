class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        vector<int>dp(warehouse.size(),0);
        priority_queue<int, vector<int>, greater<int>>pq;
        dp[0] = warehouse[0];
        pq.push(dp[0]);
        for(int i = 1; i < warehouse.size(); ++i) {
            dp[i] = min({warehouse[i],dp[i-1]});
            pq.push(dp[i]);
        }
        sort(boxes.begin(), boxes.end());
        int index = 0;
        int count = 0;
        while (!pq.empty() and index < boxes.size()) {
            int num = pq.top(); pq.pop();
            if (num >= boxes[index]) {
                count++;
                index++;
            }
        }

        return count;
    }
};
