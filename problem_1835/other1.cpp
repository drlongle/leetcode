/*
We all know the distributive property that (a1+a2)*(b1+b2) = a1*b1 + a1*b2 + a2*b1 + a2*b2
Now focus on each bit,
for example the last bit of A[i] and B[j],
and think how it works and affect the result.
*/

class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        int xora = 0, xorb = 0;
        for (int& a: A)
            xora ^= a;
        for (int& b: B)
            xorb ^= b;
        return xora & xorb;
    }
};
