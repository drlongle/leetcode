class Solution {
  public:
    string gcdOfStrings(string str1, string str2) {
        // the game of observation
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(
            0, __gcd(str1.length(),
                     str2.length())); // we know about gcd of two numbers
    }
};
