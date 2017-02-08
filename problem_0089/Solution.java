/*
89. Gray Code

    Total Accepted: 67152
    Total Submissions: 178194
    Difficulty: Medium

The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
*/

import java.io.*;
import java.util.*;

public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> last_set = new ArrayList<>();
        if (n == 0)
            return Arrays.asList(0);

        last_set.add(0);
        last_set.add(1);
        List<Integer> res = last_set;
        if (n == 1)
            return res;

        for (int i = 2; i <= n; ++i)
        {
            res = new ArrayList<>();
            res.addAll(last_set);
            for (int j = last_set.size()-1; j >= 0; --j)
                res.add( 1 << (i-1) | last_set.get(j));
            last_set = res;
        }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        Scanner in = new Scanner(System.in);
        System.out.print("Input: ");
        int n = in.nextInt();
        List<Integer> res = sol.grayCode(n);
        for (Integer r: res)
            System.out.println(r + " --> " + Integer.toBinaryString(r));
    }
}

