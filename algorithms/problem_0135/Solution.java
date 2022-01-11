/*
135. Candy

    Total Accepted: 58732
    Total Submissions: 250463
    Difficulty: Hard

There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
*/

import java.io.*;
import java.util.*;

public class Solution {
    public int candy(int[] ratings)
    {
        int length = ratings.length;
        int[] left = new int[length];
        Arrays.fill(left, 1);
        for (int i = 1; i < length; ++i)
            if (ratings[i] > ratings[i-1])
                left[i] = left[i-1]+1;

        int[] right = new int[length];
        Arrays.fill(right, 1);
        for (int i = length-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1])
                right[i] = right[i+1]+1;

        int sum = 0;
        for (int i = 0; i < length; ++i)
            sum += Math.max(left[i], right[i]);

        return sum;
    }

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        int ratings[] = {100, 4, 200, 1, 3, 2};
        System.out.println("Result: " + sol.candy(ratings));
    }
}
