class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        int sum = 0;
        while (sum < target) sum += (++k);
        const int d = sum - target;
        if (d % 2 == 0) return k;
        return k + 1 + (k % 2);
    }
};
