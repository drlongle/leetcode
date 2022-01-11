class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n)
            return 0;
        if(k == n)
            return 1;
        vector<int> f(26);
        for(int i = 0; i < n; i++)
            f[s[i] - 'a']++;
        
        int c = 0;
        for(int i = 0; i < 26; i++)
        {
            if(f[i] % 2 == 1)
                c++;
        }
        return c <= k;
    }
};
