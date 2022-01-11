class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        
        stack<pair<int, int>> points;
        for (int i = 0; i < heights.size(); ++i) {
            auto index = i;
            
            while (!points.empty() && points.top().second > heights[i]) {
                auto current = points.top();
                points.pop();
                
                index = current.first;
                result = max(result, (i - index) * current.second);
            }
            
            points.push({index, heights[i]});
        }
        
        while (!points.empty()) {
            auto current = points.top();
            points.pop();
            
            result = max(result, ((int)heights.size() - current.first) * current.second);
        }
        
        return result;
    }
};

