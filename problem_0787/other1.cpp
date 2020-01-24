class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector< vector< pair< long, long > > > graph( n, vector< pair< long, long > >() );
        queue< tuple< long, long, long > > q; // dist, hops, city

        for( auto &i : flights ) {
            int from, to, dist, hops;
            from = i[ 0 ], to = i[ 1 ], dist = i[ 2 ];
            
            graph[ from ].emplace_back( to, dist );
            if( from == src ) {
                dist = hops = 0;
            } else {
                dist = hops = INT_MAX;
            }
        }

        q.emplace( 0, 0, src );
        vector< long > minDist( n, INT_MAX ); // maintain minDist of each node.
        minDist[ src ] = 0;
        while( not q.empty() ) {
            long currCity, currDist, currHops;
            tie( currDist, currHops, currCity ) = q.front(), q.pop();
            // cout << "Curr: " << currCity
            //      << ", currDist: " << currDist
            //      << ", currHops: " << currHops << endl;
            if( minDist[ currCity ] > currDist ) continue;
            for( auto &n : graph[ currCity ] ) {
                // cout << "    : " << n.first << ", dist: " << n.second << endl;
                if( currDist + n.second > minDist[ n.first ] or currHops + 1 > K + 1 ) continue;
                q.emplace( currDist + n.second, currHops + 1, n.first );
                minDist[ n.first ] = min( minDist[ n.first ], currDist + n.second );
            }
        }
        
        return ( minDist[ dst ] == INT_MAX ) ? -1 : minDist[ dst ];
    }
};
