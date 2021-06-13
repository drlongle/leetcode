class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int n = S.length();
        unordered_map<char, int> charCount;
        int end = 0, start = 0 , res = 0, count = 0;
        while(end < n)
        {
            if(charCount[S[end]]++ == 0)
            {
                count++;
            }
            end++;
            if(end - start > K)
            {
                if(--charCount[S[start]] == 0)
                {
                    count--;
                }
                start++;
            }
            if(count == K && end - start == K)
            {
                res++;
            }
        }
        return res;
    }
};
