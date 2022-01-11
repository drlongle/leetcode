class Solution {
public:
    int dp[27][27][301] = {};    
    int cost(char from, char to) {
        if (from == 26) return 0;
        return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
    }
    int minimumDistance(string &word, int pos = 0, char left = 26, char right = 26) {
        if (pos >= word.size()) return 0;
        if (dp[left][right][pos] == 0) {
            auto to = word[pos] - 'A';
            dp[left][right][pos] = min(cost(left, to) + minimumDistance(word, pos + 1, to, right),
                                       cost(right, to) + minimumDistance(word, pos + 1, left, to)) + 1;
        }
        return dp[left][right][pos] - 1;
    }
};
