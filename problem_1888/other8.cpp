class Solution {
    int even, odd, tones, tzeros, ans;
public:
    int minFlips(string s) {
        for(int i = 1; i <= s.size(); ++i) {
            if(s[i-1] == '1') {
                ++tones;
                if(i % 2 == 0) ++even;
            } else {
                ++tzeros;
                if(i % 2 == 1) ++odd;
            }
        }
        ans = min(even + odd, tones - even + tzeros - odd);
        for(int i = 1; i <= s.size(); ++i) {
            even = tones-even;
            odd = tzeros-odd;
            if(s.size() % 2 == 1) {
                if(s[i-1] == '1') --even;
                else ++odd;
            }
            ans = min({ans, even + odd, tones - even + tzeros - odd});
        }
        return ans;
    }
};
