/*
223. Rectangle Area

    Total Accepted: 41236
    Total Submissions: 135112
    Difficulty: Easy

Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as
shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int computeArea(int A, int B, int C, int D)
    {
        return Math.abs((A-C)*(B-D));
    }

    public boolean overlap(int A, int B, int C, int D,
        int E, int F, int G, int H)
    {
         return (!(A > G || E > C || B > H || F > D));
    }

    public int computeArea(int A, int B, int C, int D,
        int E, int F, int G, int H)
    {
        int res = computeArea(A,B,C,D) + computeArea(E,F,G,H);
        if (overlap(A,B,C,D,E,F,G,H))
        res -= computeArea(Math.max(A,E),Math.max(B,F),
            Math.min(C,G),Math.min(D,H));

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums;
        nums = new int[] {-2, -2, 2, 2, -3, 1, -1, 3};
        System.out.println("Result: " +
            sol.computeArea(nums[0],nums[1], nums[2], nums[3],
            nums[4], nums[5], nums[6], nums[7]));
    }
}

