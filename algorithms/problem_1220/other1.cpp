#define rep(i,n) for(int i=0;i<n;i++)
// Initialize a matrix construct
long long m=1e9+7;
struct Matrix{
    vector< vector<long long> >a=vector<vector<long long>>(5,vector<long long>(5,0));
    Matrix operator *(const Matrix& other){
        Matrix product;
        rep(i,5)rep(j,5)rep(k,5){
                    product.a[i][k]=((product.a[i][k])+(a[i][j]) * (other.a[j][k]))%m;
                }
        return product;
    }
};
// Function for binary exponentiation of matrices
Matrix binpow(Matrix a, long long b) {
    Matrix res;
    rep(i,5)res.a[i][i]=1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}


class Solution {
public:
    int countVowelPermutation(int n) {

        Matrix Transition;
        Transition.a[0][1]=1;
        Transition.a[0][2]=1;
        Transition.a[0][4]=1;

        Transition.a[1][0]=1;
        Transition.a[1][2]=1;

        Transition.a[2][1]=1;
        Transition.a[2][3]=1;

        Transition.a[3][2]=1;

        Transition.a[4][2]=1;
        Transition.a[4][3]=1;

        Matrix ans=binpow(Transition,n-1);
        long long sum=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                sum=(sum+ans.a[i][j])%m;
            }
        }
        return sum;
    }
};
