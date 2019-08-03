class Solution {
public:
    int memo[10005];
    int util(vector<vector<int>>& books, int sw, int idx)
    {
        if (idx == books.size())
            return 0; // no more height
        if (memo[idx])
            return memo[idx];
        int gh = INT_MAX;
        int cw = 0; // stores cumulative width
        int ch = INT_MIN;
        for (int i = idx; i < books.size(); i++) {
            int w = books[i][0];
            int h = books[i][1];
            cw += w;
            if (cw > sw)
                break;       // cannot recurse now
            ch = max(ch, h); // keeps track of max height in this recursive call
            gh = min(gh, ch + util(books, sw, i + 1));
        }
        return memo[idx] = gh;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width)
    {
        return util(books, shelf_width, 0);
    }
};
