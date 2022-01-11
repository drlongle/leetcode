class Solution {
public:
    string rearrangeString(string& s, int k) {
        vector<int> count(26);
        for (char c : s) ++count[c - 'a'];
        vector<int> last(26, -1);

        int n = s.size();
        for (int m = 0; m < n; ++m) {
            int max = -1;
            for (int i = 0; i < 26; ++i) {
                if (count[i] == 0) {
                    continue;
                }

                if (last[i] >= 0 && m - last[i] < k) {
                    continue;
                }

                if (max < 0 || count[i] > count[max]) {
                    max = i;
                }
            }

            if (max < 0) {
                return string();
            }

            s[m] = 'a' + max;
            --count[max];
            last[max] = m;
        }

        return s;
    }
};
