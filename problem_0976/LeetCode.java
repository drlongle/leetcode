/*
Sort the array. For any c in the array, we choose the largest possible a <= b <= c: these are just the two values adjacent to c. If this forms a triangle, we return the answer.
*/

class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        for (int i = A.length - 3; i >= 0; --i)
            if (A[i] + A[i+1] > A[i+2])
                return A[i] + A[i+1] + A[i+2];
        return 0;
    }
}
