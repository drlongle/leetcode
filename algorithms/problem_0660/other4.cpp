class Solution {
public:
    int newInteger(int n) {
        // count from 0 to make the code cleaner
        // the number of numbers containing 9 with one digits is 1
        // the number of numbers containing 9 with two or one digits: (8+1) * 1 + 10 = 19
        // the number of numbers containing 9 with three or two or one digits: (8+1) * 19 + 100
        // ...
        // the implementation finds the number directly by narrowing down the range of candidates
        if (n < 9)
            return n;

        // count from 0
        n += 1;

        vector<long> nums_without_nine;
        long num = 9, removed = 1, mul = 1;
        nums_without_nine.push_back(num);

        while (num < n) {
            // number of numbers containing 9
            removed = 9 * removed + mul * 10;
            mul *= 10;
            // number of numbers not containing 9
            num = mul * 10 - removed;
            nums_without_nine.push_back(num);
        }

        int size = nums_without_nine.size();
        n -= nums_without_nine[size-2];

        // locate the target number
        int ans = mul, i = size-2;
        while (n > 0) {
            if (i < 0) {
                return ans + n - 1;
            }
            if (n > nums_without_nine[i]) {
                n -= nums_without_nine[i];
                ans += mul;
            }
            else {
                i--;
                mul /= 10;
            }
        }
        return ans;
    }
};
