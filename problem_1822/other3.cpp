class Solution
{
public:
    int arraySign(vector<int>& nums)
    {
        int negCount = 0;
        for ( int x : nums ) {
            if ( x == 0 )
                return 0;
            else if ( x < 0 )
                negCount++;
        }
        return negCount%2==1 ? -1 : 1;
    }
};
