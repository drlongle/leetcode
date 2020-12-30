class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {

        vector<unordered_set<int>> aCols (A.size(), unordered_set<int>());
        for (int i=0; i < A.size();i++){
            for (int j=0; j<A[0].size();j++){
                if (A[i][j] != 0) aCols[i].insert(j);
            }
        }

        vector<unordered_set<int>> bRows (B[0].size(), unordered_set<int>());
        for (int j=0; j < B[0].size();j++){
            for (int i=0; i<B.size();i++){
                if(B[i][j]!=0) bRows[j].insert(i);
            }
        }

        vector<vector<int>> C (A.size(), vector<int>(B[0].size(),0));
        for (int i=0; i < A.size();i++){
            for (int j=0; j<B[0].size();j++){
                vector<int> nonZero;
                for (auto & el: aCols[i]) if (bRows[j].count(el) != 0) nonZero.push_back(el);
                int curr =0 ;
                for (auto & el : nonZero) curr+=A[i][el]*B[el][j];
                C[i][j] = curr;
            }
        }

        return C;

    }
};
