class Solution {
public:
    bool halvesAreAlike(string s) {
        const string::size_type half_length = s.length() / 2;
        int result = 0;
        for (int i = 0; i < half_length; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                result++;
            }

            if (s[i + half_length] == 'a' || s[i + half_length] == 'e' || 
                s[i + half_length] == 'i' || s[i + half_length] == 'o' || 
                s[i + half_length] == 'u' || s[i + half_length] == 'A' ||
                s[i + half_length] == 'E' || s[i + half_length] == 'I' ||
                s[i + half_length] == 'O' || s[i + half_length] == 'U') {
                result--;
            }
        }
        
        return result == 0;
    }
};

