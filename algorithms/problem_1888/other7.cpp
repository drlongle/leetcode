class Solution {
public:

    int minFlips(string s) {
        int n = s.length();
        int v[n];

        for(int i = 0; i < n; i++) {
            v[i] = (s[i] - '0');
        }

        int even[n], odd[n];

        even[0] = (v[0] == 0 ? 0 : 1); // start with even 010101
        odd[0] = (v[0] == 0 ? 1 : 0); // start with odd 101010

        for(int i = 1; i < n; i++) {
            if (i % 2 == 0) { // even
                even[i] = even[i-1] + (v[i] == 0 ? 0 : 1);
                odd[i] = odd[i-1] + (v[i] == 1 ? 0 : 1);
            } else {
                even[i] = even[i-1] + (v[i] == 1 ? 0 : 1);
                odd[i] = odd[i-1] + (v[i] == 0 ? 0 : 1);
            }
        }

        int res = min(odd[n - 1], even[n - 1]); // no Type-1 operation

        // states
        // even[] -> e o e o e -> 1 shift -> o e o e e -> odd[n-1] - odd[i] + even[i]
        // odd[] -> o e o e o -> 1 shift -> e o e o o -> even[n-1] - even[i] + odd[i]

        if (n % 2 != 0) {
            for(int i = 0; i < n; i++) {
                res = min(res, odd[n-1] - odd[i] + even[i]);
                res = min(res, even[n-1] - even[i] + odd[i]);
            }
        }

        return res;
    }
};
