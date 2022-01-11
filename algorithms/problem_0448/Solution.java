/*
448. Find All Numbers Disappeared in an Array

    Total Accepted: 1252
    Total Submissions: 1890
    Difficulty: Easy
    Contributors: yuhaowang001

Given an array of integers where 1 <= a[i] <= n (n = size of array), some
elements appear twice and others appear once. Find all the elements of [1, n]
inclusive that do not appear in this array. Could you do it without extra
space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

import java.io.*;
import java.util.*;

public class Solution {

    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int numlen = nums.length;
        for (int i = 0; i < numlen; ++i)
        {
            int index = nums[i] - 1;
            if (index < 0)
                index += numlen;
            if (nums[index] >= 0)
                nums[index] -= numlen;
        }
        
        for (int i = 0; i < numlen; ++i)
        {
            int index = nums[i] - 1;
            if (index >= 0)
                res.add(i+1);
        }
        
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = new int[] {4,3,2,7,8,2,3,1};

        List<Integer> res = sol.findDisappearedNumbers(nums);
        System.out.println("Result: " + res);
    }
}
