class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        if (n & 1) {
            int mid = n/2;
            for (int i = 0; i < mid; ++i)
                res += 2 * (mid - i);
        } else {
            int mid = (n-1)/2;
            for (int i = 0; i <= mid; ++i)
                res += 1 + 2 * (mid - i);
        }
        return res;
    }
};
