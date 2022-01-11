// For each position where we need to climb, we try using brick and ladder, and log the maximum index we can reach

class Solution {
    int ans = 0;
    void dfs(vector<int> &H, int B, int L, int start) {
        if (ans == H.size() - 1) return;
        if (start == H.size() - 1) {
            ans = H.size() - 1;
            return;
        }
        for (int i = start; i < H.size(); ++i) {
            ans = max(ans, i);
            if (H[i] == 0) continue;
            if (B >= H[i])
                dfs(H, B - H[i], L, i + 1);
            if (L)
                dfs(H, B, L - 1, i + 1);
            break;
        }
    }
public:
    int furthestBuilding(vector<int>& H, int B, int L) {
        for (int i = 0; i + 1 < H.size(); ++i)
            H[i] = max(0, H[i + 1] - H[i]);
        H.back() = 0;
        dfs(H, B, L, 0);
        return ans;
    }
};
