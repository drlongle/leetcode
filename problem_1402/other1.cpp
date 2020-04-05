/*
Intuition
If we cook some dishes,
they must be the most satisfied among all choices.

Another important observation is that,
we will cook the dish with small satisfication,
and leave the most satisfied dish in the end.

Explanation
We choose dishes from most satisfied.
Everytime we add a new dish to the menu list,
all dishes on the menu list will be cooked one time unit later,
so the result += total satisfaction on the list.
We'll keep doing this as long as A[i] + total > 0.
 */

class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] > -total; --i) {
            total += A[i];
            res += total;
        }
        return res;
    }
};
