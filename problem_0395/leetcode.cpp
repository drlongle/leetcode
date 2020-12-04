/*
The string would be split only when we find an invalid character. An invalid
character is the one with a frequency of less than k. As we know, the invalid
character cannot be part of the result, we split the string at the index where
we find the invalid character, recursively check for each split, and combine
the result.

Algorithm
- Build the countMap with the frequency of each character in the string s.
- Find the position for mid index by iterating over the string. The mid index
  would be the first invalid character in the string.
- Split the string into 2 substrings at the mid index and recursively find the result.

To make it more efficient, we ignore all the invalid characters after the mid index as well, thereby reducing the number of recursive calls.
*/

class Solution {
    public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return longestSubstringUtil(s, 0, n, k);
    }
    int longestSubstringUtil(string &s, int start, int end, int k) {
        if (end < k) return 0;
        int countMap[26] = {0};
        // update the countMap with the count of each character
        for (int i = start; i < end; i++)
            countMap[s[i] - 'a']++;
        for (int mid = start; mid < end; mid++) {
            if (countMap[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s[midNext] - 'a'] < k) midNext++;
            return max(longestSubstringUtil(s, start, mid, k),
                    longestSubstringUtil(s, midNext, end, k));
        }
        return (end - start);
    }
};


