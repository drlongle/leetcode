class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boarding_cost, int running_cost) {
        int maximum_profit = 0, maximum_profit_run = -1, boarded = 0, waiting = 0;
        for (auto i = 0; i < customers.size() || waiting > 0; i++) {
            if (i < customers.size()) {
                // Add customers arriving just before ith rotation to waiting customers.
                waiting += customers[i];
            }

            // Update total boarded customers. At most 4 customers can board, but if there are less than 4 customers waiting, then only those will board.
            boarded += min(4, waiting);

            // Reduce the number of waiting customers.
            waiting = max(0, waiting - 4);

            // Compute the profit after current rotation.
            auto current_profit = (boarded * boarding_cost) - ((i + 1) * running_cost);
            if (maximum_profit < current_profit) {
                maximum_profit = current_profit;
                maximum_profit_run = i + 1;
            }
        }

        // If maximum profit possible is not positive, return -1. Otherwise return the rotation after which profit is maximum.
        return maximum_profit > 0 ? maximum_profit_run : -1;
    }
};
