
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, int> m;
        for(auto const& edge : edges) m[edge[1]] = edge[0];
        int result = 0;
        for(int i = 0; i < hasApple.size(); ++i) {
            if (!hasApple[i]) continue;
            int parent = i;
            while(parent != 0 && m[parent] >= 0) {
                auto temp = m[parent];
                m[parent] = -1;
                parent = temp;
                result += 2;
            }
        }
        return result;
    }
};
