/*
We try to use all bricks first, storing elevations in the priority queue. When we do not have enough bricks, we replace
some bricks with a ladder. We need to trade the largest number of bricks - which is the highest elevation on the top of
the priority queue.
 */

class Solution {
public:
    int furthestBuilding(vector<int>& hs, int bricks, int ladders) {
        priority_queue<int> pq;
        for (auto i = 1; i < hs.size(); ++i) {
            auto d = hs[i] - hs[i - 1];
            if (d > 0) {
                if (d <= bricks) {
                    pq.push(d);
                    bricks -= d;
                }
                else if (ladders--) {
                    if (!pq.empty() && pq.top() > d) {
                        bricks += pq.top() - d;
                        pq.pop();
                    }
                }
                else
                    return i - 1;
            }
        }
        return hs.size() - 1;
    }
};