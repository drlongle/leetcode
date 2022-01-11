// Just trace the index of any one variable until its index is equal to the required index.
// Multiplying by 2 because if we observe the movement of any variable it is equivalent to some multiple of 2
// modulus is to keep the value of index valid(<n).
// Asymptotic behavior : I believe its not more than n.

class Solution {
public:
    int reinitializePermutation(int n)
    {
        int ind=1;
        int ct=0;

        if(n==2)
            return 1;

        while(1)
        {
            ind=ind*2;
            ct++;
            if(ind>=(n-1))
                ind=ind%(n-1);

            if(ind==1)
                return ct;
        }
    }
};
