# The problem here is given a bunch piles of chips and you merge them into one pile with min cost.
# It's trivial if only given one pile if chips. For more than one, you seperate piles into two groups,
# one having even distance with the first pile and the rest are the other group and then return the
# min of the sum of these two groups.
# The reason is, for piles with each other of even distance unit, you can merge them together with 0 cost.
# By this criteria, piles can only be divided into two groups.

class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even = sum(1 for c in chips if c & 1)
        odd = len(chips) - even
        if even == 0 or even == len(chips):
            return 0
        return min(even, odd)
 
