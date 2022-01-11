class Solution {
public:
    string addBinary(string a, string b) {
        ostringstream oss;
        int i = a.size() -1, j = b.size() - 1, c = 0;
        while (i >= 0 || j >= 0 || c) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            oss << (c % 2);
            c /= 2;
        }
        
        string str = oss.str();
        reverse(begin(str), end(str));
        return str;
    }
};
