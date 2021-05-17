/*
Intuition

Say P = R^2 is a superpalindrome.

Because R is a palindrome, the first half of the digits in R determine R up
to two possibilities. We can iterate through these digits: let k be the first
half of the digits in R. For example, if k = 1234, then R = 1234321 or
R = 12344321. Each possibility has either an odd or an even number of digits in R.

Notice because P < 10^18 and R = k | k' (concatenation), where k' is k reversed 
(and also possibly truncated by one digit); so that k < 10^5 = MAGIC, our magic constant.

*/

class Solution {
    public int superpalindromesInRange(String sL, String sR) {
        long L = Long.valueOf(sL);
        long R = Long.valueOf(sR);
        int MAGIC = 100000;
        int ans = 0;

        // count odd length;
        for (int k = 1; k < MAGIC; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 2; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        // count even length;
        for (int k = 1; k < MAGIC; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 1; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }

        return ans;
    }

    public boolean isPalindrome(long x) {
        return x == reverse(x);
    }

    public long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }

        return ans;
    }
}
