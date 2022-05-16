class Solution {
  public:
    string removeDigit(string s, char digit) {
        int n = s.size(), last_occurence = -1, target = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == digit) {
                last_occurence = i;
                break;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == digit && s[i + 1] > s[i]) {
                target = i;
                break;
            }
        }
        if (target != -1) {
            s.erase(s.begin() + target);
        } else if (last_occurence != -1) {
            s.erase(s.begin() + last_occurence);
        }
        return s;
    }
};
