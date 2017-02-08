/*
128. Longest Consecutive Sequence

    Total Accepted: 78253
    Total Submissions: 229628
    Difficulty: Hard

Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

For example: Given [100, 4, 200, 1, 3, 2], the longest consecutive elements
sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
 */

import java.io.*;
import java.util.*;

public class Solution
{
    public void swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public int split(int[] nums, int i, int j)
    {
        int pivot = nums[j];
        int threshold = j;
        int index = i;

        if (i == j)
            return i;

        while (index <= threshold)
        {
            if (nums[index] >= pivot)
            {
                swap(nums, index, threshold);
                if (index <= threshold)
                    threshold--;
            }
            else
                ++index;
        }

        return threshold;
    }

    public int median(int[] nums, int i, int j)
    {
        int mid = i + ((j-i) >> 1);
        int m = i;
        do {
            m = split(nums, m, j);
        } while (m < mid);

        return nums[mid];
    }

    public int longestConsecutive(int[] nums, int i, int j)
    {
        System.out.println("Median: " + median(nums, i, j));
        return 0;
    }

    int[] longestConsecutive(List<Integer> nums)
    {
        int n = nums.get(0);
        int[] result = new int[] {n,n};
        int[] running = new int[] {n,n};
        for (int i = 1; i < nums.size(); ++i)
        {
            n = nums.get(i);
            if (n > running[1] + 1)
            {
                if (running[1] - running[0] > result[1] - result[0])
                {
                    result[0] = running[0];
                    result[1] = running[1];
                }
                running[0] = running[1] = n;
            }
            else
                running[1] = n;
        }

        if (running[1] - running[0] > result[1] - result[0])
        {
            result[0] = running[0];
            result[1] = running[1];
        }

        return result;
    }

    public int longestConsecutive(int[] nums)
    {
        if (nums.length == 0)
            return 0;

        numIntervals = new TreeMap<>();
        for (int i = 0; i < nums.length; ++i)
        {
            int index = nums[i] / arraySize;
            if (!numIntervals.containsKey(index))
                numIntervals.put(index, new ArrayList<Integer>());
            numIntervals.get(index).add(nums[i]);
        }
        
        int[] longest = null;
        int[] running = null;
        for (Map.Entry<Integer, List<Integer>> entry : numIntervals.entrySet())
        {
            List<Integer> array = entry.getValue();
            Collections.sort(array);
            int[] temp = longestConsecutive(array);
            if (running != null)
            {
                if (running[1]+1 == temp[0])
                    running[1] = temp[1];
                else
                {
                    if (running[1] - running[0] > longest[1] - longest[0])
                    {
                        longest[0] = running[0];
                        longest[1] = running[1];
                    }
                    running[0] = temp[0];
                    running[1] = temp[1];
                }
            }
            else
            {
                longest = new int[2];
                running = new int[2];
                longest[0] = running[0] = temp[0];
                longest[1] = running[1] = temp[1];
            }
        }

        if (running[1] - running[0] > longest[1] - longest[0])
        {
            longest[0] = running[0];
            longest[1] = running[1];
        }
        
        System.out.println("Longest: " + longest[0] + " -> " + longest[1]);

        return longest[1] - longest[0] + 1;
    }

    public static final int arraySize = 100; 
    private Map<Integer, List<Integer>> numIntervals;

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        int nums[] = {100, 4, 200, 1, 3, 2};
        System.out.println("Result: " + sol.longestConsecutive(nums));
    }
}

