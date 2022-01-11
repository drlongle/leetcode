class Solution {
public:
    int minCost(vector<vector<int>>& costs)
    {
        vector<int> colors(3, 0);

        for (auto cost : costs)
        {
            vector<int> temp(3, 0);
            temp[0] = cost[0] + min(colors[1], colors[2]);
            temp[1] = cost[1] + min(colors[0], colors[2]);
            temp[2] = cost[2] + min(colors[0], colors[1]);

            colors.swap(temp);
        }

        return * min_element(colors.begin(), colors.end());
    }
};
