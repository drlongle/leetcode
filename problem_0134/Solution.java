/*
134. Gas Station

    Total Accepted: 65838
    Total Submissions: 236478
    Difficulty: Medium

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class SumEntry
    {
        SumEntry(int f, int l, int s)
        {
            first = f;
            last = l;
            sum = s;
        }

        public int first;
        public int last;
        public int sum;
    }

    public SumEntry find_max_sum(int[] diff)
    {
        int length = diff.length;
        int max_sum = 0;
        int sum_so_far = 0;
        int first, last, current_first, current_last;
        first = current_first = 0;
        last = current_last = 0;

        for (int i = 0; i < length; ++i)
        {
            if (sum_so_far < 0)
            {
                current_first = current_last = i;
                sum_so_far = 0;
            }
            sum_so_far += diff[i];
            current_last = i;
            if (sum_so_far > max_sum)
            {
                first = current_first;
                last = current_last;
                max_sum = sum_so_far;
            }
        }

        return new SumEntry(first, last, max_sum);
    }

    public SumEntry find_min_sum(int[] diff)
    {
        int length = diff.length;
        int min_sum = 0;
        int sum_so_far = 0;
        int first, last, current_first, current_last;
        first = current_first = 0;
        last = current_last = 0;

        for (int i = 0; i < length; ++i)
        {
            if (sum_so_far > 0)
            {
                current_first = current_last = i;
                sum_so_far = 0;
            }
            sum_so_far += diff[i];
            current_last = i;
            if (sum_so_far < min_sum)
            {
                first = current_first;
                last = current_last;
                min_sum = sum_so_far;
            }
        }

        return new SumEntry(first, last, min_sum);
    }

    public int canCompleteCircuit(int[] gas, int[] cost) {
        int length = gas.length;
        int[] diff = new int[length];
        int total_sum = 0;

        for (int i = 0; i < length; ++i)
        {
            diff[i] = gas[i] - cost[i];
            total_sum += diff[i];
        }

        SumEntry min_no_wrap = find_min_sum(diff);
        SumEntry max_no_wrap = find_max_sum(diff);
        SumEntry min_wrap = new SumEntry((max_no_wrap.last+1) % length,
        max_no_wrap.first > 0 ?
            max_no_wrap.first - 1 : length - 1, total_sum - max_no_wrap.sum);

        int last, index, min_sum;
        if (min_wrap.sum < min_no_wrap.sum)
        {
            index = (max_no_wrap.last+1) % length;
            min_sum = min_wrap.sum;
            if (total_sum < 0)
                return -1;
        }
        else
        {
            index = min_no_wrap.first;
            min_sum = min_no_wrap.sum;
        }

        for (int i = 0; min_sum < 0 && i < length; ++i)
        {
            if (--index < 0)
                index += length;
            min_sum += diff[index];
        }

        return (min_sum < 0) ? -1 : index;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] gas, cost;

        // Expected: 0 
        gas = new int[] {10, 10, 6, 7, 8};
        cost = new int[] {9, 8, 8, 8, 8};
        System.out.println("Result: " + sol.canCompleteCircuit(gas, cost));
    }
}

