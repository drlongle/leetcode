/*
Let's tackle the following problem:
Size of longest subsequence of
s1*n = s1 s1 ... s1 (n times) which is a equal to a prefix of
s2[j:] s2 ...... (infinite times) where s2[j:] is in python notation

Now let dp[i][j] be the solution for n=2^i and j

Finding dp[0][j] can be done by brute force.

for(int i=0;i<s2.size();i++){
	dp[0][i] = 0;
	for(int j=0;j<s1.size();j++){
		if(s1[j]==s2[(i+dp[0][i])%s2.size()]) dp[0][i]++;
	}
}
And we have recurrence relation: dp[i+1][j] = m + dp[i][(j+m)%N] where m = dp[i][j] and N = size of s2.

Reason:

Let n = 2^i then for dp[i+1][j] we need to find size of subsequence for s1*n + s1*n matching with s2[j:] s2 s2 ....

Then s1*n has m matches which introduces an additional offset of m%N , hence the relation dp[i+1][j] = m + dp[i][(j+m)%N]

So we can find the dp in O(32) time. And the result can be calculated in the following way

for(int i=0;i<32;i++){
	if(n1%2 == 1) {
		int m = dp[i][offset];
		k += m;
		offset = (offset+m)%s2.size();
	}
	n1 /= 2;
}
 */

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
#define int long long
        const int N = 32;
        vector<vector<int>> dp(N, vector<int>(s2.size()));

        for(int i=0;i<s2.size();i++){
            dp[0][i] = 0;
            for(int j=0;j<s1.size();j++){
                if(s1[j]==s2[(i+dp[0][i])%s2.size()]) dp[0][i]++;
            }
        }



        for(int i=1;i<N;i++){
            for(int j=0;j<s2.size();j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][(j+dp[i-1][j])%s2.size()];
            }
        }

        int k = 0;
        int offset = 0;
        for(int i=0;i<N;i++){
            if(n1%2 == 1) {
                int m = dp[i][offset];
                k += m;
                offset = (offset+m)%s2.size();
            }
            n1 /= 2;
        }
#undef int
        return k/(n2*s2.size());
    }

};