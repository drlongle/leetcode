class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 0:
            return 0
        same, different = 0, k
        for i in range(2, n + 1):
            same, different = different, (different + same) * (k - 1)
        return same + different
