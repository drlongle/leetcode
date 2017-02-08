/*
456. 132 Pattern

    User Accepted: 127
    User Tried: 315
    Total Accepted: 128
    Total Submissions: 873
    Difficulty: Medium

Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence
ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that
takes a list of n numbers as input and checks whether there is a 132 pattern
in the list.

Note: n will be less than 15,000.

Example 1:

Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.

Example 2:

Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:

Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2],
[-1, 3, 0] and [-1, 2, 0].
 */

import java.io.*;
import java.util.*;

public class Solution {

    public boolean find132pattern(int[] nums) {
        if (nums == null || nums.length < 3)
            return false;
        
        int leftMinNumber = nums[0];
        TreeMap<Integer, Integer> rightNumbers= new TreeMap<>();
        for (int i = 1; i < nums.length; ++i)
            rightNumbers.merge(nums[i], 1, Integer::sum);

        for (int i = 1; i < nums.length-1; ++i)
        {
            int key = nums[i];
            int counter = rightNumbers.get(key);
            if (counter == 1)
                rightNumbers.remove(key);
            else
                rightNumbers.put(key, counter-1);

            if (key <= leftMinNumber)
            {
                if (key < leftMinNumber)
                    leftMinNumber = key;
                continue;
            }

            Map.Entry<Integer, Integer> rightEntry =
                rightNumbers.higherEntry(leftMinNumber);
            if (rightEntry != null && rightEntry.getKey() < key)
                return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums;
        
        nums = new int[] {1, 2, 3, 4};
        nums = new int[] {3, 1, 4, 2};
        nums = new int[] {-1, 3, 2, 0};

        System.out.println("Result: " + sol.find132pattern(nums));
    }
}

