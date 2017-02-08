/*
169. Majority Element
Total Accepted: 124020 Total Submissions: 293508 Difficulty: Easy

Given an array of size n, find the majority element. The majority element is
the element that appears more than  n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

import java.io.*;
import java.util.*;

public class Solution {

    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int count = 0;

        for (int i = 0; i < nums.length; ++i)
        {
            if (count == 0)
            {
                count = 1;
                candidate = nums[i];
            }
            else if (candidate == nums[i])
                ++count;
            else 
                --count;
        }
        return candidate;
    }

    public static void main(String[] args) {

    }
}

