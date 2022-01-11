class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Deque = deque< int >;
    using Map = unordered_map< int,int >;
    using Memo = unordered_map< int,int >;
    VI corpFlightBookings( VVI& B, int N, Map M={} ){
        for( auto& b: B ){
            auto[ i,j,k ] = tie( b[ 0 ],b[ 1 ],b[ 2 ] );
            M[ i ] += k;
            M[ j+1 ] -= k;
        }
        Deque ans( N+1 );
        go( N, M, ans );
        ans.pop_front();
        return{ ans.begin(), ans.end() };
    }
private:
    int go( int i, Map& M, Deque& ans, Memo&& memo={} ){
        if( memo.find( i ) != memo.end() )
            return memo[ i ];
        if( i == 0 )
            return memo[ i ] = 0;
        return ans[ i ] = memo[ i ] = M[ i ] + go( i-1, M, ans, move( memo ) );
    }
};
