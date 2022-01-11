/*
372. Super Pow

    Total Accepted: 62
    Total Submissions: 249
    Difficulty: Medium

Your task is to calculate a^b mod 1337 where a is a positive integer and b is an
extremely large positive integer given in the form of an array.

Example1:
a = 2
b = [3]
Result: 8

Example2:
a = 2
b = [1,0]
Result: 1024
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int superPow(int a, int[] b)
    {
        long result = 1;
        a %= mod_factor;

        for (int i = b.length-1; i >= 0; --i)
        {
            for (int j = 0; j < b[i]; ++j)
                result = (result * a) % mod_factor;
            int new_a = 1;
            for (int j = 0; j < 10; ++j)
                new_a = new_a * a % mod_factor;
            a = new_a; 
        }

        return (int) result;
    }

    public static final int mod_factor = 1337;

    public static void main(String[] args) {
        Solution sol = new Solution();
        int a;
        int[] b;

        // Expected: 8
        a = 2;
        b = new int[] {3};
        System.out.println("Result: " + sol.superPow(a,b));
    }
}

