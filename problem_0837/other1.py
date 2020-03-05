# Take one example first:
# N = 12, W = 10, K = 10
#
# The stop range for the game is [10, 10 + 10 -1] which is [K, K + W -1]
# dp[i] means if the target K is set to this one what is the possiblty to be <=N

# For i <= W
# dp[0] = 1.0 for sure
# dp[1] = 1.0 / W because one of W chance we get 1
# dp[2] = dp[1] / W + 1 / W we have 2 ways to get 2 here, 1 + 1 and 0 + 2
# dp[3] = dp[2] / W + 1 / W
# and so on, we can see this is a GP until i reach W, so dp[i] = (dp[i-1] + 1.0) / 2
# To reach value i which is bigger than W, you must start from some previous value i in range [i - w, i - 1], so the possibilty smaller than that is not possible
#
# For example i = 11, previous value range is [1, 10], but there is no such part of 1/W because no value of single draw can be > W, so we don't do the addition here. Instead, we need to reduce the change of value 1 after move to next value
#
# dp[11] = dp[1] + dp[2] ... + dp[10]
# dp[12] = dp[2] + d[3] ... + dp[10]
#
# Everytime we move to the next, get rid of the leftmost value.
#
# The function stops at reach N.
#
# Here we use a Wsum to carry the sum to the next dp everytime.
#
# And the values end in range
# [10, min(10 + 10 -1, N)] will be the result
#

class Solution:
    """
    @param N: int
    @param K: int
    @param W: int
    @return: the probability
    """
    def new21Game(self, N, K, W):
        # Write your code here.
        if K == 0 or N >= K + W: 
            return 1.0
        dp = [1.0] + [0.0] * N
        Wsum = 1.0
        for i in range(1, N + 1):
            dp[i] = Wsum / W
            if i < K: 
                Wsum += dp[i]
            if i - W >= 0: 
                Wsum -= dp[i - W]
        return sum(dp[K:])
