/*
Trick 1: k can be too big, so skip full circles by only considering k % sum(chalk).
Trick 2: sum(chalk) array can exceed INT_MAX, use long (0l) to accumulate.
*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= accumulate(begin(chalk), end(chalk), 0l);
        for (int i = 0; i < chalk.size(); ++i)
            if ((k -= chalk[i]) < 0)
                return i;
        return 0;
    }
};