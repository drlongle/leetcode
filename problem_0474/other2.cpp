class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v( m+1 , vector<int>( n+1 , 0 ) );
        int l = strs.size();
        int i , j , k , z , o ;
        for (int i = 0 ; i < l ; i++ ) { // include ith string and update the vector v[m][n]
            o = count(strs[i].begin(), strs[i].end() , '1' );
            z = strs[i].size() - o;
            for(j = m ; j >= z ; j--) { // j should be greater than z( no of zeroes )
                for( k = n ; k >= o ; k-- ) {  // k should be greater than o ( no of ones )
                    v[j][k] = max( v[j][k] , 1+v[ j - z ][ k - o ] ); 
                }// for k 
            }// for j 
        }
        return v[m][n];
    }
};
