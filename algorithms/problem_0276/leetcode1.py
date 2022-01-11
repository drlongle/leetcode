class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 0: return 0
        # you can either use @functools.lru_cache
        # or you can implement an array to store
        # the values manually
        # more details: https://docs.python.org/3/library/functools.html
        @lru_cache(None)
        def total_ways(num):
            if num == 1:
                return k
            if num == 2:
                return k * k
            last = total_ways(num - 1)
            second_last = total_ways(num - 2)
            return (last + second_last) * (k - 1)

        return total_ways(n)
