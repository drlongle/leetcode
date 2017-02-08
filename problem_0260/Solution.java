/*
260. Single Number III

    Total Accepted: 39250
    Total Submissions: 86613
    Difficulty: Medium

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int[] singleNumber(int[] nums) {
        int[] res = new int[2];
        int xor = 0, len = nums.length;
        for (int i = 0; i < len; ++i)
            xor ^= nums[i];

        int s;
        for (s = 0; s < 32; ++s)
            if ((xor & (1 << s)) != 0)
                break;

        int res1 = 0;
        for (int i = 0; i < len; ++i)
        {
            if (((1 << s) & nums[i]) != 0)
                res1 ^= nums[i];
        }

        res[0] = xor ^ res1;
        res[1] = res1;

        return res; 
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums, res;

        // expected: [3, 5].
        nums = new int[] {1, 2, 1, 3, 2, 5};
        res = sol.singleNumber(nums);
        System.out.println(res[0] + ", " + res[1]);
    }
}

