class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0, sz = position.size();
        for (int i = 0; i < sz; ++i) {
            if (position[i] % 2 == 0)
                ++even;
            else
                ++odd;
        }
        
        return min(even, odd);
    }
};
