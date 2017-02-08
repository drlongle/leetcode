/*
377. Combination Sum IV

    Total Accepted: 2656
    Total Submissions: 6857
    Difficulty: Medium

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.
Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int combinationSum4(int[] nums, int target)
    {
        int[] ways = new int[target+1];
        ways[0] = 1;

        for (int i = 0; i <= target; ++i)
            for (int n: nums)
                if (n <= i)
                    ways[i] += ways[i-n];

        return ways[target];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums;
        int target;

        // Expected: 7
        nums = new int[]{1, 2, 3};
        target = 4;
        System.out.println("Result: " + sol.combinationSum4(nums, target));
    }
}

