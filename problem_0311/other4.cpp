class Solution {
public:
    int multiplication(unordered_map<int,int> A,unordered_map<int,int> B){
        int sum = 0;
        for(auto it:A){
            sum+= it.second*B[it.first];
        }
        return sum;
    }
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int dimAi = A.size();
        int dimAj = A[0].size();
        int dimBi = B.size();
        int dimBj = B[0].size();

        vector<vector<int>> AB(dimAi,vector<int>(dimBj,0));

        unordered_map<int,unordered_map<int,int>> sparseA;
        unordered_map<int,unordered_map<int,int>> sparseB;

        for(int i=0;i<dimAi;i++){
            for(int j=0;j<dimAj;j++){
                if(A[i][j]!=0){
                    sparseA[i][j] = A[i][j];
                }
            }
        }

        for(int i=0;i<dimBi;i++){
            for(int j=0;j<dimBj;j++){
                if(B[i][j]!=0){
                    sparseB[j][i] = B[i][j];
                }
            }
        }

        for(auto it:sparseA){
            for(auto it2:sparseB){
                AB[it.first][it2.first] = multiplication(sparseA[it.first],sparseB[it2.first]);
            }
        }

        return AB;
    }
};
