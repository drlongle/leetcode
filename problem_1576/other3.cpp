class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); ++i){
            if (s[i] != '?') continue;
            int before = -1, after = -1;
            if (i != 0){
                before = s[i-1];
            }
            if (i < s.length() - 1){
                after = s[i+1];
            }
            int j;
            do{
                j = rand()%26 + 97;
            } while (j == before || j == after);
            s[i] = (char) j;
        }
        return s;
    }
};
