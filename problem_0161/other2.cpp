class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if(sLen < tLen) {
            return isOneEditDistance(t, s);
        }
        if(sLen - tLen > 1) return false;
        if(!tLen && sLen == 1) return true;
        int i = 0, j = 0, one = false;
        while(i < sLen && j < tLen){
            while(i < sLen && j < tLen && s[i] == t[j]) {
                i++;
                j++;
            }
            if(i < sLen && j < tLen && one) return false;

            if(i < sLen && j < tLen && !one){
                one = true;
                if(sLen == tLen) {
                    i++;
                    j++;
                }
                else {
                    i++;
                }

            }
            else if(i == sLen && j != tLen && !one){
                one = true;
                j++;
            }
            else if(j == tLen && i != sLen && !one){
                i++;
                one = true;
            }
        }
        return one && i == sLen && j == tLen;
    }
};
