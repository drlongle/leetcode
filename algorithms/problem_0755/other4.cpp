class Solution {
public:
    void addDrop(vector<int>& heights, int idx) {
        // Skip all heights to our left that are equal to heights[idx] until
        // we find a column with height smaller than heights[idx]
        int l_idx = idx;
        while (l_idx >= 0 && heights[l_idx] <= heights[idx]) {
            if (heights[l_idx] < heights[idx]) {
                // Found a column to our left
                addDrop(heights, l_idx);
                return;
            }
            l_idx--;
        }

        // Skip all heights to our right that are equal to heights[idx] until
        // we find a column with height smaller than heights[idx]
        int r_idx = idx;
        while (r_idx < heights.size() && heights[r_idx] <= heights[idx]) {
            if (heights[r_idx] < heights[idx]) {
                // Found a column to our right
                addDrop(heights, r_idx);
                return;
            }
            r_idx++;
        }

        // No left or right option, we can only add the drop here
        heights[idx]++;
    }

    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while (V) {
            addDrop(heights, K);
            V--;
        }
        return heights;
    }
};
