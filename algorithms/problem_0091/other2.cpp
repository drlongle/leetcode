class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return helper(s, memo, 0);
    }
    
    int helper(string &s, vector<int> &memo, int i)
    {
        if(i>=s.length())
            return 1;
        if(memo[i]>=0)
            return memo[i];
        int r = 0;
        if (s[i] != '0')
            r += helper(s, memo, i+1);
        if(i < s.length() - 1 && ((s[i] == '2' && s[i+1]<'7') || s[i]=='1'))
            r+= helper(s, memo, i+2);
        memo[i] = r;
        return memo[i];
    }
};

