/*
303. Range Sum Query - Immutable
Total Accepted: 34632 Total Submissions: 137801 Difficulty: Easy

Given an integer array nums, find the sum of the elements between indices
i and j (i <= j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
    You may assume that the array does not change.
    There are many calls to sumRange function.
*/

import java.io.*;

public class NumArray {

    public NumArray(int[] nums) {
        int length = nums.length;
        prefix_sum = new int[nums.length];

        for (int i = 0; i < nums.length; ++i)
            prefix_sum[i] = (i > 0 ? prefix_sum[i-1] : 0) + nums[i];
    }

    public int sumRange(int i, int j) {
        return prefix_sum[j] - (i > 0 ? prefix_sum[i-1] : 0); 
    }

    int[] prefix_sum;

    // Your NumArray object will be instantiated and called as such:
    // NumArray numArray = new NumArray(nums);
    // numArray.sumRange(0, 1);
    // numArray.sumRange(1, 2);

    public static void main(String[] args) {
        int[] nums = {-2, 0, 3, -5, 2, -1};
        NumArray numArray = new NumArray(nums);
        int i, j;

        i = 0;
        j = 2;
        System.out.println("Res: " + numArray.sumRange(i,j));
    }
}

