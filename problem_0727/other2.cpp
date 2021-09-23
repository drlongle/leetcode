class Solution {
public:
    string minWindow(string s1, string s2) {

        int res = s1.size(), start = -1;

        if (s1 == s2) return s1;

        for (int i=0,j=0; i<s1.size(); ) {
            if (s1[i] != s2[j]) {
                i++;
                continue;
            }
            j++;
            if (j == s2.size()) {

                int tIndex = j-2;
                int sIndex = i-1;
                while (tIndex >=0 ) {
                    while (s1[sIndex] != s2[tIndex]) sIndex--;
                    tIndex--;
                    sIndex--;
                }
                j = 0;

                if (i - sIndex < res) {
                    res = i-sIndex;
                    start = sIndex+1;
                }
                i = sIndex + 2;
            } else i++;

        }
        return start == -1 ? "" : s1.substr(start, res);

    }
};
