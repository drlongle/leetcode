class Solution {
public:
    int longestRepeatingSubstring(string S) {
        vector vect(S.size()+1,0);
        int maxi=0, temp, pre;
        for(int i=1; i<=S.size(); i++)
        {
            temp = vect[i-1];
            for(int j=i; j<=S.size(); j++)
            {
                pre = vect[j];
                if(S[i-1]==S[j-1])
                    vect[j] = 1 + temp;
                else
                    vect[j] = 0;
                temp = pre;
                if(i!=j && vect[j]>maxi)
                    maxi = vect[j];
            }
        }
        return maxi;
    }
};
