class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') a++;
                else b++;
            }
        }
        if ((a + b) & 1) return -1;
        int ans = (a + 1) / 2 + (b + 1) / 2;
        return ans;
    }
};
