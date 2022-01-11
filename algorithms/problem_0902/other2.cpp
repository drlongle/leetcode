
class Solution {
    int cnt, current, n;
    string strn;
    void helper(vector<string>& digits,long power,int index) {
        if (power==0){
            if (current<=n) cnt++;
        }
        else {
            for (int i = 0; i < digits.size(); i++) {
                if (digits[i][0] < strn[index] - '0') {
                    if (power != 1)
                        cnt += pow(digits.size(), log10(power));
                    else
                        cnt++;
                } else if (current + digits[i][0] * power <= n) {
                    current += digits[i][0] * power;
                    helper(digits, power / 10, index + 1);
                    current -= digits[i][0] * power;
                } else break;
            }
        }
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int szp = log10(n);//size of progression
        this->n = n;
        for (string& s:digits) s[0]-='0';
        strn = to_string(n);
        sort(digits.begin(),digits.end());
        cnt = current = 0;
        helper(digits,pow(10,szp),0);
        if (digits.size()==1) return cnt+szp;
        return digits.size()*(pow(digits.size(),szp)-1)/(digits.size()-1)+cnt;
    }
};
