class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; i++){
            int pos = K;
            while (pos > 0){
                if (heights[pos-1] <= heights[pos]) pos --;
                else break;
            }
            while (pos < K){
                if (heights[pos+1] == heights[pos]) pos ++;
                else break;
            }
            if (pos == K){
                while (pos < heights.size()-1){
                    if (heights[pos+1] <= heights[pos]) pos ++;
                    else break;
                }
                while (pos > K){
                    if (heights[pos-1] == heights[pos]) pos --;
                    else break;
                }
            }
            heights[pos] ++;
        }
        return heights;
    }
};
