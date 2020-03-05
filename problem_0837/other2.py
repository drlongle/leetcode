# dp(n) means the probability getting point "n" at any count of draws.
# e.g. when random number is 1~3, we have:
# dp(n)=dp(n-3)*(1/3)+dp(n-2)*(1/3)+dp(n-1)*(1/3)
# And this kind of sum can be optimized using sliding window sum.
#
# We cannot iterate DP on draw count, because it is hard to decide when to stop iterating.
# Instead we iterate on the obtained point, because each point can be obtained by the dp value of previous points.

class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        if K==0 or K-1+W<=N:
            return 1
        dp=[1]+[0]*N
        cursum=1
        for i in range(1,N+1):
            # dp[i]=sum(dp[max(0,i-W):min(i,K)])*(1/W)
            dp[i]=cursum*(1/W)
            if i<K:
                cursum+=dp[i]
            if i>=W:
                cursum-=dp[i-W]
        return sum(dp[K:])
