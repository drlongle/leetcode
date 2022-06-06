class Solution {
  public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {

        const int m1 = s1.length();
        const int m2 = s2.length();

        int pos1 = 0, pos2 = 0;
        int k1 = 0, k2 = 0;

        vector<pair<int, int>> history(m2, {-1, -1}); // <pos2, <k1,k2>>

        history[0] = {0, 0};

        while (k1 < n1) {
            if (s1[pos1++] == s2[pos2]) {
                if (++pos2 == m2) {
                    ++k2, pos2 = 0;
                }
            }

            if (pos1 == m1) {
                ++k1, pos1 = 0;

                if (history[pos2].first == -1) {
                    history[pos2] = {k1, k2};
                } else {
                    auto [prev_k1, prev_k2] = history[pos2];

                    if (prev_k2 == k2)
                        return 0; // cannot obtain s2 from [s1,n1]

                    // fast forward k1 and k2 based on the found cycle
                    if (k1 < n1) {
                        // calc the largest q, s.t. k1 + q * (k1 - prev_k1) <=
                        // n1
                        int q = (n1 - k1) / (k1 - prev_k1);
                        k1 += q * (k1 - prev_k1);
                        k2 += q * (k2 - prev_k2);
                    }
                }
            }
        }

        return k2 / n2;
    }
};
