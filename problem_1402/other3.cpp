/*
All dishes with satisfaction >= 0 should be cooked, in the order of increasing the satisfaction. Now, we can also cook the dish with a smallest negative satisfaction, and see if a negative value is ofset by extra time bonus. If so, repeat with the next smallest negative satisfaction.
 */

class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(begin(sat), end(sat));
        int run_sum = accumulate(begin(sat), end(sat), 0), total_sum = 0;
        for (auto i = 0; i < sat.size(); ++i)
            total_sum += (i + 1) * sat[i];
        for (auto i = 0; run_sum < 0 && i < sat.size(); ++i) {
            total_sum -= run_sum;
            run_sum -= sat[i];
        }
        return total_sum;
    }
};
