/*
Think about the most straightforward solution: find the minimum element in the first row,
add it to the minimum element in the second row, and so on.

That should work, unless two minimum elements are in the same column. To account for that, let's
remember the position pos of the minimum element fm. Also, we need to remember the second
minimum element sm.
For the next row, we will use fm for columns different than pos, and sm otherwise.
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int fm = 0, sm = 0, pos = -1;
        for (auto i = 0; i < arr.size(); ++i) {
            auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
            for (auto j = 0; j < arr[i].size(); ++j) {
                auto mn = j != pos ? fm : sm;
                if (arr[i][j] + mn < fm2) {
                    sm2 = fm2;
                    fm2 = arr[i][j] + mn;
                    pos2 = j;
                } else sm2 = min(sm2, arr[i][j] + mn);
            }
            fm = fm2, sm = sm2, pos = pos2;
        }
        return fm;
    }
};
