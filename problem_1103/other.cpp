#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int n)
    {
        long l = 0, r = 1000000;
        long long ans = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long check = ((n * mid) * (n * mid + 1)) / 2; // the power of binary search!
            if (check <= candies) {
                ans = mid, l = mid + 1;
            } else
                r = mid - 1;
        }
        vector<int> val(n, 0);
        for (int i = 1; i <= n; i++) {
            val[i - 1] = ans * i + (n * (ans) * (ans - 1)) / 2;
            candies -= val[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            if (!candies)
                break;
            if (candies >= ans * n + i) {
                val[i - 1] += ans * n + i;
                candies -= ans * n + i;
            } else
                val[i - 1] += candies, candies = 0;
        }
        return val;
    }
};
