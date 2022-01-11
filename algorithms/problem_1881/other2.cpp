class Solution {
public:
    string maxValue(string n, int x) {
        for (int i = 0; i < size(n); ++i) {
            if ((n[0] == '-' && x < n[i] - '0') || (n[0] != '-' && x > n[i] - '0'))
                return n.substr(0, i) + to_string(x) + n.substr(i);
        }
        return n + to_string(x);
    }
};
