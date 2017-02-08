/*
 442. Find All Duplicates in an Array

    Total Accepted: 2654
    Total Submissions: 5948
    Difficulty: Medium
    Contributors: shen5630

Given an array of integers, 1 <= a[i] <= n (n = size of array), some elements
appear twice and others appear once.

Find all the elements that appear twice in this array. Could you do it without
extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
 */

import java.io.*;
import java.util.*;

public class Solution {

    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int numlen = nums.length;
        for (int i = 0; i < numlen; ++i)
        {
            int index = nums[i]-1;
            while (index < 0)
                index += numlen;
            nums[index] -= numlen;
        }

        for (int i = 0; i < numlen; ++i)
        {
            if (nums[i] <= -numlen)
                res.add(i+1);
        }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = new int [] {4,3,2,7,8,2,3,1};

        nums = new int[] {2,2};

        List<Integer> res = sol.findDuplicates(nums);
        System.out.println("Result: " + res);
    }
}

