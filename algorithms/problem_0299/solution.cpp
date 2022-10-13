class Solution {
  public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        map<char, int> cnt;

        for (char c : secret)
            ++cnt[c];
        int bulls{0}, cows{0};

        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
                --cnt[secret[i]];
                guess[i] = 0;
            }
        }
        for (char c : guess) {
            if (--cnt[c] >= 0)
                ++cows;
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
