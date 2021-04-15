# Contributed by LeetCode user mereck.
# Generalized Fibonacci Sequence and the Golden Ratio
# https://demonstrations.wolfram.com/GeneralizedFibonacciSequenceAndTheGoldenRatio/
class Solution:
    def fib(self, N):
        golden_ratio = (1 + 5 ** 0.5) / 2
        return int((golden_ratio ** N + 1) / 5 ** 0.5)
