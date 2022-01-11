/*
The idea is to keep track of counts of each vovel while transforming from a string of length k
to length k+1 and then loop for all values of k. The number of vowels in each loop iteration
will change according to the rules given.
*/

public class Solution {
    public int countVowelPermutation(int n) {
        if (n == 1) return 5;
        
        int aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        
        final int MOD = 1000000007;
        
        for (int i=2; i<=n; ++i) {
            int aCountNew = ((eCount + uCount) % MOD + iCount) % MOD;
            int eCountNew = (aCount + iCount) % MOD;
            int iCountNew = (eCount + oCount) % MOD;
            int oCountNew = iCount;
            int uCountNew = (iCount + oCount) % MOD;
			
            aCount = aCountNew;
            eCount = eCountNew;
            iCount = iCountNew;
            oCount = oCountNew;
            uCount = uCountNew;
        }
        
        return (((((((aCount + eCount) % MOD) + iCount) % MOD) + oCount) % MOD) + uCount) % MOD;
    }
}
