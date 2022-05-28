class Solution {
  public:
    string smallestGoodBase(string n) {
        stringstream in;
        in << n;
        long long value, l, h, m, x, val;
        in >> value;
        bool f = false;
        for (int i = 63; i >= 1; i--) {
            l = 2;
            h = value - 1;
            while (l <= h) {
                m = l + (h - l) / 2;
                val = 1;
                x = 1;
                int flag = 0;
                for (int j = 1; j < i; j++) {
                    if (val >= value)
                        break;
                    if (j < i && ((value - val) / x) < m) {
                        flag = 1;
                        break;
                    }
                    x = x * m;
                    val += x;
                }
                if (val > value || flag == 1)
                    h = m - 1;
                else if (val < value)
                    l = m + 1;
                else {
                    string str = to_string(m);
                    return str;
                }
            }
        }
        return " ";
    }
};
