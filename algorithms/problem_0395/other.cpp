class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringUtil(s, k);
    }
private:    
    int longestSubstringUtil(string s, int k) {
        int count[26] = {0};
        int maxLen = 0;
        int i = 0, j = 0;
        
        // count frequencies for every element
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Divide the string into as many substrings as possible as apposed
        // to just two strings. This helps in saving the above step of recounting
        // again and again.
        for (; i < s.size(); i++) {
            if (count[s[i] - 'a'] && count[s[i] - 'a'] < k) {
                if (i - j) {
                    maxLen = max(maxLen, longestSubstringUtil(s.substr(j, i - j), k));
                }
                j = i + 1;
            }
        }
        
        // if we reached the end we didn't find any breaking character
        // this means the entire string is valid if the length of the string
        // is more than k
        if (j == 0 && i - j >= k) {
            maxLen = max(maxLen, (int)s.size());
        } else if (j != 0 && i == s.size()) {
            // This is a tricky case.
            // This covers the case when we reach the end but we haven't recursed
            // for the last part of the string after the last invalid char
            maxLen = max(maxLen, longestSubstringUtil(s.substr(j, i - j), k));
        }
        
        return maxLen;
    }
};
