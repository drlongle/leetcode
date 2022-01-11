class Solution {
public:
    size_t ans = 0;
    void reach(vector<int>& heights, int bricks, int ladders, size_t index) {
        if (ans + 1 == heights.size() || (index == heights.size() - 1)) {
            ans = heights.size() - 1;
            return;
        }
        for (; index < heights.size(); ++index) {
            ans = max(ans, index);
            if (index == heights.size() - 1)
                break;
            int dh = heights[index+1] - heights[index];
            if (dh <= 0)
                continue;

            if (ladders > 0)
                reach(heights, bricks, ladders-1, index+1);
            if (bricks >= dh)
                reach(heights, bricks - dh, ladders, index+1);

            break;
        }
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        reach(heights, bricks, ladders, 0);
        return ans;
    }
};
