class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size() ==0 || B.size() ==0 || A[0].size() != B.size()){
            return {{}};
        }
        unordered_map<int,int> Alist;
        unordered_map<int,int> Blist;
        int m = A.size();
        int k = B.size();
        int n = B[0].size();
        vector<vector<int>> C(m,vector<int>(n,0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < k; ++j){
                if(A[i][j] != 0){
                    Alist[i*k + j] = A[i][j];
                }
            }
        }
        for(int i = 0; i < k; ++i){
            for(int j = 0; j < n; ++j){
                if(B[i][j] != 0){
                    Blist[i*n + j] = B[i][j];
                }
            }
        }
        for(auto ait : Alist){
            for(int j = 0; j< n; ++j){
                auto bit = Blist.find(j + n * (ait.first % k));
                if( bit != Blist.end()){
                    C[ait.first/k][j] += ait.second * bit->second;
                }
            }
        }
        return C;
    }
};
