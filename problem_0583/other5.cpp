class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size() + 1, n2 = word2.size() + 1;
        vector<vector<int>> t(n1,vector<int>(n2));

        for(int y = 0; y != n1; y++) t[y][0] = 0;
        for(int x = 1; x != n2; x++) t[0][x] = 0;

        for(int y = 1,py = 0; y != n1; y++, py++)
            for(int x = 1, px = 0; x != n2; x++, px++)
                if(word1[py] == word2[px]) t[y][x] = t[py][px] + 1;
                else t[y][x] = max(t[y][px], t[py][x]);

        return n1 + n2 - 2 - 2*t[n1-1][n2-1] ;
    }
};
