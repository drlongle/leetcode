class Solution:
    def thousandSeparator(self, n: int) -> str:
        s = str(n)
        res = ""
        n = len(s)
        for i in range(n):
            res += s[i]
            diff = n - i - 1
            if diff > 0 and diff % 3 == 0:
                res += '.'
        return res

