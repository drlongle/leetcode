/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> cand(n, true);

        for (int i = 0; i < n; ++i) {
            if (!cand[i])
                continue;
            for (int j = 0; cand[i] && j < n; ++j) {
                if (i == j)
                    continue;
                if (knows(i, j))
                    cand[i] = false;
                if (knows(j, i))
                    cand[j] = false;
                else
                    cand[i] = false;
            }
            if (cand[i])
                return i;
        }

        return -1;
    }
};