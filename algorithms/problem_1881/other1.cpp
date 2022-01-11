class Solution {
public:
    string maxValue(string n, int x) {
        for (auto i = 0; i < n.size(); ++i)
            if (n[0] == '-' ? n[i] - '0' > x : n[i] - '0' < x)
                return n.substr(0, i) + char('0' + x) + n.substr(i);
        return n + char('0' + x);
    }
};
