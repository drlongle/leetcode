class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return k
        second_last, last = k, k * k
        for i in range(n - 2):
            second_last, last = last, (second_last + last) * (k - 1)
        return last
