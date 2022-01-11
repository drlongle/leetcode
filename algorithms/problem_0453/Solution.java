/*
453. Minimum Moves to Equal Array Elements

    User Accepted: 334
    User Tried: 763
    Total Accepted: 357
    Total Submissions: 905
    Difficulty: Easy

Given a non-empty integer array of size n, find the minimum number of moves
required to make all array elements equal, where a move is incrementing
n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int minMoves(int[] nums) {
        int numlen = nums.length;
        if (numlen < 2)
            return 0;
        Arrays.sort(nums);
        int res = 0;
        int index = 0;
        while (index < numlen -1 && nums[index+1] == nums[index])
            ++index;
        while (index < numlen -1)
        {
            int diff = nums[numlen-1] - nums[index];
            if (diff == 0)
                break;
            res += diff;
            nums[index] += diff;
            int temp = nums[numlen-1];
            for (int i = numlen - 1; i > index; --i)
                nums[i] = nums[i-1] + diff;
            nums[index+1] = temp;
            while (index < numlen-1 && nums[index+1] == nums[index])
                ++index;
        }
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = new int[] {1,2,3,4,5};

        int res = sol.minMoves(nums);
        System.out.println("Result: " + res);
    }
}
