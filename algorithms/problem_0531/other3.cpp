/*
1. populate bitset with 1 in the position where 'B' is encountered
2. If count of bits in row is > 1, this row should not be included, but bits have to
   be added to the mask and later the mask is applied to ensure those bits are not set
3. bp holds the cumulative bits. bp is ORed with row bitset and mask is applied to make
   sure all bits are unset in the columns where we had 'B' before.
4. Return final bit count.
 */

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture)
    {
        bitset<501> bp, bc, mask;
        mask.set();

        for( int i = 0; i < picture.size(); ++i )
        {
            for( int j = 0; j < picture[0].size(); ++j )
                bc[j] = (picture[i][j] == 'B');

            if( bc.count() == 1 )     mask &= ~(bp&bc);
            else if( bc.count() > 1 ) mask &= ~bc;

            bp = ((bp|bc)&mask);
            bc.reset();
        }

        return bp.count();
    }
};
