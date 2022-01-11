// Convert to base 9.

class Solution {
public:
    int newInteger(int n) {
        string res;
        while (n>0){
            res.push_back(n%9 + '0');
            n /= 9;
        }
        reverse(res.begin(), res.end());
        return stoi(res);
    }
};
