class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        vector<int> levels;
        int level = INT_MAX;

        for(auto &ware : warehouse)
        {
            level = min(level,ware);
            levels.push_back(level);
        }

        priority_queue<int,vector<int>,greater<int>> pq;

        for (auto& b : boxes) pq.push(b);
        for(int i = levels.size() - 1; i >= 0; i--)
        {
            if(pq.size() && pq.top() <= levels[i]) pq.pop();
        }
        return boxes.size() - pq.size();
    }
};
