/*
right is the number of the right most lighted bulb.

Iterate the input light A,
update right = max(right, A[i]).

Now we have lighted up i + 1 bulbs,
if right == i + 1,
it means that all the previous bulbs (to the left) are turned on too.
Then we increment res
 */
class Solution {
public:
    int numTimesAllBlue(vector<int>& A) {
        int right = 0, res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            res += (right = max(right, A[i])) == i + 1;
        return res;
    }
};
