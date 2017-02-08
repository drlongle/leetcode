/*
454. 4Sum II

    User Accepted: 230
    User Tried: 408
    Total Accepted: 231
    Total Submissions: 900
    Difficulty: Medium

Given four lists A, B, C, D of integer values, compute how many tuples
(i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where
0 <= N <= 500. All integers are in the range of -2^28 to 2^28 - 1 and the
result is guaranteed to be at most 2^31 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

import java.io.*;
import java.util.*;

public class Solution {

    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int i = 0; i < C.length; ++i)
            for (int j = 0; j < D.length; ++j)
                counter.merge(C[i] + D[j], 1, Integer::sum);

        int res = 0;
        for (int i = 0; i < A.length; ++i)
            for (int j = 0; j < B.length; ++j)
                res += counter.getOrDefault(-(A[i] + B[j]), 0);

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] A, B, C, D;

        A = new int[]{1, 2};
        B = new int[]{-2,-1};
        C = new int[]{-1, 2};
        D = new int[]{0, 2};

        System.out.println("Result: " + sol.fourSumCount(A, B, C, D));
    }
}
