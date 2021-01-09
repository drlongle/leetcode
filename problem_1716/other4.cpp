class Solution {
public:
    int totalMoney(int n, int start = 1, int day = 0, int x = 0, int total = 0) {
        while (n--) {
            if (day++ % 7 == 0)
                x = start++;
            total += x++;
        }
        return total;
    }
};
