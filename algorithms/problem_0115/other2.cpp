class Solution {
public:
    int numDistinct(string s, string t) {
        int table[t.size()] = {0};
        for(char c:s){
            for(int i = t.size() - 1; i >= 0; i--){
                if(t[i] == c){
                    if(i == 0) ++table[0];
                    else table[i] += table[i - 1];
                }
            }
        }
        return table[t.size() - 1];
    }
};

