
// reverse the search order from [k-1, k, k+1] to [k+1, k, k-1]

class Solution {
public:
    bool canCross(vector<int>& stones, int cur_pos, int k) {
        int len = stones.size();
        if (stones[len - 1] * 2 > len * (len - 1)) {
            return false;
        }
        if (cur_pos + 1 == len) {
            return true;
        }
        for (int j = k + 1; j >= k - 1; j--) {
            for (int i = cur_pos + 1; i < len; i++) {
                if (stones[i] - stones[cur_pos] > j) {
                    break;
                }
                if (stones[i] - stones[cur_pos] == j) {
                    if (canCross(stones, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2) {
            return false;
        }
        if (stones[0] != 0 || stones[1] != 1) {
            return false;
        }
        return canCross(stones, 1, 1);
    }
};
