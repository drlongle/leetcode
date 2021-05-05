class Solution {
public:
    int jump(vector<int>& N) {
        int len = N.size() - 1, curr = N[0], next = curr, ans = 2;
        if (len == 0) return 0;
        if (len <= curr) return 1;
        for (int i = 1; next < len; i++) {
            if (i > curr) ans++, curr = next;
            next = max(next, N[i] + i);
        };
        return ans;
    }
};
