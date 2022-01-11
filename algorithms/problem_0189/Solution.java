/*
189. Rotate Array

    Total Accepted: 79135
    Total Submissions: 362587
    Difficulty: Easy

Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public void reverse(int[] nums, int begin, int end)
    {
        while (begin < end)
        {
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }

    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = new int[] {1,2,3,4,5,6,7};
        int k = 3;
        sol.rotate(nums, k);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < nums.length; ++i)
        {
            sb.append(nums[i]);
            sb.append(" ");
        }
        System.out.println(sb);
    }
}

