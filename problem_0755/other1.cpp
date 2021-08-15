class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int size{(int)heights.size()};
        for(int n{0}; n < V; ++n) {
            int i{K};
            while(i > 0 && heights[i-1] <= heights[i]) --i;
            while(i < K && heights[i] == heights[i+1]) ++i;
            if(i == K) {
                int j{K};
                while(j+1 < size && heights[j+1] <= heights[j]) ++j;
                while(j > K && heights[j] == heights[j-1]) --j;
                ++heights[j];
            } else ++heights[i];
        }
        return heights;
    }
};
