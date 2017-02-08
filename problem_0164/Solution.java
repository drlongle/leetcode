/*
164. Maximum Gap

    Total Accepted: 38248
    Total Submissions: 136601
    Difficulty: Hard

Given an unsorted array, find the maximum difference between the successive
elements in its sorted form.
Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in
the 32-bit signed integer range.
*/

import java.io.*;
import java.util.*;

public class Solution
{
    public int maximumGap(List<Integer> nums)
    {
        int result = 0;
        int curr, prev = nums.get(0);
        for (int i = 1; i < nums.size(); ++i)
        {
            curr = nums.get(i);
            int diff = curr - prev;
            if (diff > result)
                result = diff;
            prev = curr;
        }

        return result;
    }

    public int maximumGap(int[] nums)
    {
        int length = nums.length;
        if (length < 2)
            return 0;

        numIntervals = new TreeMap<>();
        for (int i = 0; i < nums.length; ++i)
        {
            int index = nums[i] / arraySize;
            if (!numIntervals.containsKey(index))
                numIntervals.put(index, new ArrayList<Integer>());
            numIntervals.get(index).add(nums[i]);
        }
        
        int result = 0;
        List<Integer> prevArray = null;
        for (Map.Entry<Integer, List<Integer>> entry : numIntervals.entrySet())
        {
            List<Integer> array = entry.getValue();
            Collections.sort(array);
            int temp = maximumGap(array);
            if (temp > result)
                result = temp;
            if (prevArray != null)
            {
                temp = array.get(0) - prevArray.get(prevArray.size()-1);
                if (temp > result)
                    result = temp;
            }
            prevArray = array;
        }

        return result;
    }

    public static final int arraySize = 100;
    private Map<Integer, List<Integer>> numIntervals;

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        int nums[] = {100, 4, 200, 1, 3, 2};
        System.out.println("Result: " + sol.maximumGap(nums));
    }
}
