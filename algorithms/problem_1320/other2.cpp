/*
In our dynamic programming, dp[a] means that,
if our left finger ends at character a,
the maximum we can save is dp[a].

Now our right finger tapped all letters, and left finger did nothing.
We iterate through the whole string one by one
and select some letter to tap with the left finger.
By doing this, we want to find out the maximum distance that we can save from the tapping with one finger.

Assume that our left finger is at a now,
our right finger is at b,
and we the right finger will tap c next.

Instead of moving right finger from b to c with distance d(b, c),
we try moving left finger from a to c with distance d(a, c).
Hopely this will save d(b, c) - d(a, c).

And finaly, we have one fingers at b and the other at c now.
The finger at b will be new left finger, and the other will be the right.
*/
class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        int res = 0, save = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};
