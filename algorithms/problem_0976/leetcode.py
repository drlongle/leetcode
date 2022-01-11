# Sort the array. For any c in the array, we choose the largest possible a <= b <= c: these are just the two values adjacent to c. If this forms a triangle, we return the answer.

class Solution(object):
    def largestPerimeter(self, A):
        A.sort()
        for i in xrange(len(A) - 3, -1, -1):
            if A[i] + A[i+1] > A[i+2]:
                return A[i] + A[i+1] + A[i+2]
        return 0
