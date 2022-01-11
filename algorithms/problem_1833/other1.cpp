class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        std::size_t i = 0;
        while (i < costs.size() && coins >= 0 && costs[i] <= coins)
            coins -= costs[i++];
        return i;
    }
};
