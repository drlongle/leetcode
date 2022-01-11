class Solution {
public:
    int closestToTarget(vector<int> a, int target) {
        int n = a.size();
        int cur = a[0], ans = abs(a[0] - target);
        for (int i = 1; i < n; i++) {
            if (cur < target) cur = a[i];
            cur &= a[i];
            ans = min(ans, abs(cur - target));
        }
        return ans;
    }
};
