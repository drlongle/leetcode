class Solution {
  public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int cnt = 0;
        int mark_s1 = -1, mark_n1 = -1, mark_cnt = -1, bLastPeriod = false;
        int i, j, k = 0;
        for (i = 0; i < n1; i++) {
            for (j = 0; j < s1.length(); j++) {
                if (s1[j] != s2[k])
                    continue;
                if (++k >= s2.length()) {
                    k = 0;
                    cnt++;
                    if (mark_s1 == -1) {
                        mark_s1 = j;
                        mark_n1 = i;
                        mark_cnt = cnt;
                    } else {
                        if (!bLastPeriod && mark_s1 == j) // found period
                        {
                            // i-mark_n1 is period
                            int more_periods = (n1 - 1 - i) / (i - mark_n1);
                            i += (more_periods * (i - mark_n1));
                            cnt += (more_periods * (cnt - mark_cnt));
                            bLastPeriod = true;
                        }
                    }
                }
            }
        }
        return cnt / n2; // cnt is repetitions of s2. needs to divide by n2
    }
};