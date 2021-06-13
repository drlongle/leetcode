class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int ans = 0;
        int left = 0;
        int right = 0;
        vector<int> ivec(26, 0);

        if(S.length() < K) {
            return ans;
        }

        while(right < S.length()) {
            ++ivec[S[right] - 'a'];
            while(ivec[S[right] - 'a'] > 1) {
                --ivec[S[left] - 'a'];
                left++;
            }

            if (right-left+1 == K) {
                ans++;
                --ivec[S[left] - 'a'];
                left++;
            }
            right++;
        }

        return ans;
    }
};
