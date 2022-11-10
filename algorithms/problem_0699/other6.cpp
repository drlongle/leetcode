class Solution {
  public:
    // SegmentTree + Discretization
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        set<int> coords;
        for (int i = 0; i < positions.size(); ++i) {
            coords.insert(positions[i][0]);
            coords.insert(positions[i][0] + positions[i][1]);
        }

        int range = 0;
        unordered_map<int, int> h;
        for (auto &it : coords) {
            h[it] = ++range;
        }

        int max_height = 0;
        vector<int> ans;
        SegmentTree<STMax> st(range);
        ans.reserve(positions.size());
        for (int i = 0; i < positions.size(); ++i) {
            int left = positions[i][0];
            int right = positions[i][0] + positions[i][1];
            int height = st.query(h[left] + 1, h[right]) + positions[i][1];
            st.update(h[left] + 1, h[right], height);
            max_height = max(max_height, height);
            ans.push_back(max_height);
        }
        return ans;
    }
};
