class Solution {
public:
    int newInteger(int n) {
        if (n <= 8) return n;
        return 10 * newInteger(n / 9) + (n % 9);
    }
};
