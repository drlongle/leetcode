class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int j = A.size()-1,i = 0;
        while(i<j) {
            if(A[i]&1)swap(A[i],A[j--]);
            else i++;
        }
        return A;
    }
};
