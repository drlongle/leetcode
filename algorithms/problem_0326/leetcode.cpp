struct Solution {
    bool isPowerOfThree(const long n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
