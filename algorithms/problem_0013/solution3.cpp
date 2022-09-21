class Solution {
  public:
    map<char, int> table{
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
        {'X', 10},   {'V', 5},   {'I', 1},
    };
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            char c = s[i];
            int sign = 1;
            if (c == 'C') {
                if (s.find('D', i + 1) != string::npos ||
                    s.find('M', i + 1) != string::npos)
                    sign = -1;
            }

            if (c == 'X') {
                if (s.find('L', i + 1) != string::npos ||
                    s.find('C', i + 1) != string::npos)
                    sign = -1;
            }

            if (c == 'I') {
                cout << s.find('V', i + 1) << endl;
                if (s.find('V', i + 1) != string::npos ||
                    s.find('X', i + 1) != string::npos)
                    sign = -1;
            }

            res += sign * table[c];
        }

        return res;
    }
};
