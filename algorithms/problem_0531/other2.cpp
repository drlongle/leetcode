class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& p) {
        int rc=p.size();
        int cc=p[0].size();
        vector<int> c( cc, 0 );
        // traverse by columns and count number of lonely pixels;
        // there are only 3 types of condition we are interested for further check:
        // no lonely pixels; exactly 1; 2 or more
        for (int i=0 ; i < cc ; ++i)
        {
            int cnt = 0;
            // stop counting if there are 2 or more
            for (int j = 0 ; j < rc and cnt < 2 ; ++j)
                if (p[j][i] == 'B')
                    ++cnt;
            c[i] = cnt;
        }
        int res=0;
        // traverse by rows;
        // when see lonely pixel increase counter with number of lonely pixels in current column;
        // for lonely pixel counter per row will end up with 1
        for (int i=0 ; i < rc ; ++i)
        {
            int cnt = 0;
            for (int j=0 ; j < cc and cnt < 2 ; ++j)
                if (p[i][j] == 'B')
                    cnt += c[j];
            if( cnt == 1 )
                ++res;
        }
        return res;
    }
};
