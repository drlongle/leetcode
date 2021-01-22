class Solution(object):
    def maximumSwap(self, num):
        A = map(int, str(num))
        last = {x: i for i, x in enumerate(A)}
        for i, x in enumerate(A):
            for d in xrange(9, x, -1):
                if last.get(d, None) > i:
                    A[i], A[last[d]] = A[last[d]], A[i]
                    return int("".join(map(str, A)))
        return num
