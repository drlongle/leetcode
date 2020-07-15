class Solution {
public:
    int numSub(string s) {
        long res = 0;
        for(int i =0; i < s.length(); ++i)
        {
            long count = 0;
            while(s[i] == '1')
                count++, i++;
            res += count*(count+1)/2;
        }
        return res%1000000007;
    }
};