class Solution {
  public:
    string licenseKeyFormatting(string s, int k) {

        // out - to be returned
        string out;

        // add 1 to k in order to cout for the k-th + 1 occurance for adding the
        // dash '-'
        k++;

        // loop from back to front of s
        for (int i = s.size() - 1; i >= 0; i--) {

            // skip a dash
            if (s[i] != '-') {

                // if k characters has passed since last k characters, add a
                // dash to out
                if ((out.size() + 1) % k == 0) {
                    out.push_back('-');
                }

                // add the character to out
                out.push_back(toupper(s[i]));
            }
        }

        // reverse the order of out
        reverse(out.begin(), out.end());

        return out;
    }
};
