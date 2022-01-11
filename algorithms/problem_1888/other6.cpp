class Solution {
public:
    int minFlips(string s) {
        int one = 0, zero = 0;
        int n = s.length();
        // one => operation needed to convert to 101010101...
        // zero => operation needed to convert to 01010101...
        // Calculate the operation needed from current position
        for(int i = 0 ; i < n; i++)
        {
            if(i % 2 == 0 && s[i] == '0') one++;
            if(i % 2 == 1 && s[i] == '1') one++;
            if(i % 2 == 0 && s[i] == '1') zero++;
            if(i % 2 == 1 && s[i] == '0') zero++;
        }

        int ans = min(one, zero);
        int even = (n % 2) == 0;

        // This part is slightly tricky
        // Explanation above
        for(int i = 1; i < n; i++)
        {
            int new_one = even ? zero : zero - (s[i-1] != '0') + (s[i-1] != '1');
            int new_zero = even ? one : one  - (s[i-1] != '1') + (s[i-1] != '0');
            one = new_one;
            zero = new_zero;
            ans = min(ans,min(one, zero));
            if(ans == 0) break;
        }
        return ans;
    }
};
