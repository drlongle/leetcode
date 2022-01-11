class Solution {
    int[] prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
    long mod = (int)1e10 + 9;
    public boolean isScramble(String s1, String s2) {
        long anagram1 = prime[s1.charAt(0) - 'a'];
        long anagram2 = prime[s2.charAt(0) - 'a'];
        int i = 1;
        while (i < s1.length() && anagram1 != anagram2) {
            anagram1 = (anagram1 * prime[s1.charAt(i) - 'a']) % mod;
            anagram2 = (anagram2 * prime[s2.charAt(i) - 'a']) % mod;
            i++;
        }
        if (anagram1 == anagram2 && i < s1.length()) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) return true;
        }
        i = 0;
        int j = s1.length() - 1;
        anagram1 = prime[s1.charAt(i) - 'a'];
        anagram2 = prime[s2.charAt(j) - 'a'];
        i++; j--;
        while (i < s1.length() && anagram1 != anagram2) {
            anagram1 = (anagram1 * prime[s1.charAt(i) - 'a']) % mod;
            anagram2 = (anagram2 * prime[s2.charAt(j) - 'a']) % mod;
            i++; j--;
        }
        if (i == s1.length()) return s1.equals(s2);
        return isScramble(s1.substring(0, i), s2.substring(j + 1)) && isScramble(s1.substring(i), s2.substring(0, j + 1));
    }
}

