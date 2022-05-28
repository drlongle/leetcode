class Solution {
  public:
    // Try to solve the equation: x^k + x^(k-1) + ... + x^2 + x + 1 = n. (k =
    // len-1) Return the resolution, or -1 if no integer resolution
    int Solve(long n, int len) {
        // Binary search to find the resolution
        long left = 1, right = (long)pow((double)0xFFFFFFFF, 2.0 / (len - 1)),
             mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            long sum = 1, cur = mid;
            bool overflow = false;
            for (int i = 0; i < len - 1;) {
                sum += cur;
                if (++i == len - 1)
                    break;
                if (((double)cur) * mid + sum > LONG_MAX) {
                    overflow = true;
                    break;
                }
                cur *= mid;
            }
            if (overflow || sum > n)
                right = mid - 1;
            else if (sum < n)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    string smallestGoodBase(string n) {
        long val = stol(n);
        int max_len = 0; // to find the max length when int base of 2
        for (int i = 0; i <= 64; i++) {
            if (val >> i)
                continue;
            max_len = i;
            break;
        }
        long answer = val - 1; // x + 1 = n
        for (int i = 3; i <= max_len; i++) {
            int ret = Solve(val, i);
            if (ret > 0 && ret < answer)
                answer = ret;
        }
        return to_string(answer);
    }
};
