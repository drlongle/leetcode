/*
Explanation:
Whenever the current element a is bigger than the previous element,
we need at lease a - pre operations to make this difference.

We accumulate the total number of the operations,
this result is a lower bound and it's feasible.
*/
class Solution
{
public:
    int minNumberOperations(vector<int> &A)
    {
        int res = 0, pre = 0;
        for (int a : A)
        {
            res += max(a - pre, 0);
            pre = a;
        }
        return res;
    }
};