class Solution {
public:
    int largestDivisor(int num) {
        int d = sqrt(num);
        while (num % d != 0) --d;
        return d;
    }
    vector<int> closestDivisors(int num) {
        auto d1 = largestDivisor(num + 1), d2 = largestDivisor(num + 2);
        if (abs(d1 - (num + 1) / d1) < abs(d2 - (num + 2) / d2))
            return {d1, (num + 1) / d1};
        return {d2, (num + 2) / d2 };
    }
};
