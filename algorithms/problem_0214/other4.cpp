/*
The key to the problem is to find the longest palindrome starting from beginning. And it is possible to use hashing to find the longest palindrome starting from beginning in O(n) time.

To test if a string s[0..n-1] is a palindrome, calculate two values L and R as follows (K should be some prime number):
L = s[0] + s[1] * K + s[2] * K^2 + ... + s[n-1] * K^(n-1)
R = s[0] * K^(n-1) + s[1] * K^(n-2) + ... + s[n-1]
if they are the same, then s[0..n-1] is very likely a palindrome.

So, add the letters one by one and calculate the new L and R from the old ones (which can be done in O(1) time). So it takes O(n) time to test all the substrings starting from beginning.
*/

string shortestPalindrome(string s) {
        int L, R, n = s.length(), X;
        if(!n) return s;
        L = R = 0;
        X = -1;
        for(int i = 0, p137 = 1 ; i < n ; i++, p137 *= 137){
            //Update L and R
            L = L + s[i] * p137;
            R = R * 137 + s[i];
            //Update X if find a palindrome
            if(L == R) X = i;
        }
        //[0,X] is now the longest palindrome starting from begining
        string ANS;
        for(int i = n - 1 ; i > X ; i--) ANS += s[i];
        ANS += s;
        return ANS;
    }

